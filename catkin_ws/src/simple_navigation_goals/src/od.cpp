#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include "simple_navigation_goals/msg209.h"
#include <iostream>
using namespace std;
double xlinear = 0, angular = 0;
int number = 1;
void SubCallback(const simple_navigation_goals::msg209::ConstPtr& info)  
{
	xlinear = info->RXlinear;
	angular = info->Rangular;
	//ROS_INFO("SubCallback @@@ %f	%f   %d", xlinear, angular,number++);
	//cout<<"x,y = "<<xlinear<<","<<angular<<endl;
}
float vx = 0.0;
float vy = 0.0;
float vth = 0.0;

int main(int argc, char** argv){

	ros::init(argc, argv, "od");
	ros::NodeHandle n;
	ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odom", 50);
	ros::Subscriber odom_sub = n.subscribe("/car_run", 10, SubCallback); 
	tf::TransformBroadcaster odom_broadcaster;

	double x = 0.0;
	double y = 0.0;
	double th = 0.0;		

	double th_add = 0.0;  //应张东要求测试W累加
	double dt_add = 0.0;  //测试是否是dt出现问题
	ros::Time current_time;
	ros::Time last_time;
	current_time = ros::Time::now();
	last_time = ros::Time::now();
	
	tf::TransformBroadcaster broadcaster;
	ros::Rate loop_rate(20);//Hz

	// message declarations
	geometry_msgs::TransformStamped odom_trans;
	odom_trans.header.frame_id = "odom";	
	odom_trans.child_frame_id = "base_footprint";

	while (ros::ok()) {

//		ros::spinOnce();   测试是否是频率造成的原因
		vx = xlinear;
		vth = angular;

		current_time = ros::Time::now(); 
		
		double dt = (current_time - last_time).toSec();
		double delta_x = (vx * cos(th)) * dt;
		double delta_y = (vx * sin(th) ) * dt;	
		double delta_th = vth * dt;
		x += delta_x;
		y += delta_y;
		th += delta_th;
		
		geometry_msgs::Quaternion odom_quat;	
		odom_quat = tf::createQuaternionMsgFromRollPitchYaw(0,0,th);

		// update transform
		odom_trans.header.stamp = current_time; 
		odom_trans.transform.translation.x = x; 
		odom_trans.transform.translation.y = y; 
		odom_trans.transform.translation.z = 0.0;
		odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(th);

		//filling the odometry
		nav_msgs::Odometry odom;
		odom.header.stamp = current_time;
		odom.header.frame_id = "odom";
		odom.child_frame_id = "base_footprint";

		// position
		odom.pose.pose.position.x = x;
		odom.pose.pose.position.y = y;     
		odom.pose.pose.position.z = 0.0;
		odom.pose.pose.orientation = odom_quat;

		//velocity
		odom.twist.twist.linear.x = vx;
		odom.twist.twist.linear.y = 0.0;
		odom.twist.twist.linear.z = 0.0;
		odom.twist.twist.angular.x = 0.0;
		odom.twist.twist.angular.y = 0.0;
		odom.twist.twist.angular.z = vth;

		last_time = current_time;

		// publishing the odometry and the new tf
		broadcaster.sendTransform(odom_trans);
		odom_pub.publish(odom);

		ros::spinOnce();   	// 测试是否是频率造成的原因
		loop_rate.sleep();
	}
	ros::spin();
	return 0;
}
