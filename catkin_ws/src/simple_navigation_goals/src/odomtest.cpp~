#include "ros/ros.h"
#include "sensor_msgs/Range.h"
#include "std_msgs/Header.h"
#include <time.h>
#include <util.h>
#include <unistd.h> 
#include <sstream>
#include <tf/transform_broadcaster.h>
extern void send_sensor();
float u_q = 1;
float u_h = 1;
float u_left = 1;
float u_right =1;
float IR1 = 1;
float IR2 = 1;
ros::Publisher ultrasound_pub;
ros::Publisher ultrasound_pub1;
ros::Publisher ultrasound_pub2;
ros::Publisher ultrasound_pub3;
ros::Publisher ultrasound_pub4;
ros::Publisher ultrasound_pub5;
void delay(int i)
{
	int x,y,z;
	for(x = 0;x < i;x++)
		for(y = 10000; y > 0;y--)
			for(z = 50; z >0;z--);
}
void stop()
{

}

void SubCallback(const simple_navigation_goals::sensor::ConstPtr& info)  
{
	cout<<"jieshou..."<<endl;
	u_q      = (float)(info->USA)/100;	
	u_h      = (float)(info->USB)/100;
	u_left   = (float)(info->USL)/100;
	u_right = (float)(info->USR)/100;
	IR1 = (float)(info->IR0)/100;
	IR2 = (float)(info->IR1)/100;
	//cout<<"u_q: "<<u_q<<"u_h: "<<u_h<<"u_left: "<<u_left<<"u_right: "<<u_right<<"IR1: "<<IR1<<"IR2: "<<IR2<<endl;
	printf("USA[%f]  USB[%f]  USL[%f]  USR[%f]\n",u_q,u_h,u_left,u_right);
	send_sensor();
}
void send_sensor()
{
	sensor_msgs::Range msg;
	std_msgs::Header header;
	header.stamp = ros::Time::now();
	header.frame_id = "/l_ultrasound";
	msg.header = header;
	msg.radiation_type = 0;
	msg.field_of_view = 0.26;
	msg.min_range = 0.1;
	msg.max_range = 5;

	sensor_msgs::Range msg1;
	std_msgs::Header header1;
	header1.stamp = ros::Time::now();
	header1.frame_id = "/r_ultrasound";
	msg1.radiation_type = 0;
	msg1.header = header1;
	msg1.field_of_view = 0.26;
	msg1.min_range = 0.1;
	msg1.max_range = 5;

	sensor_msgs::Range msg2;
	std_msgs::Header header2;
	header2.stamp = ros::Time::now();
	header2.frame_id = "/q_ultrasound";
	msg2.header = header2;
	msg2.radiation_type = 0;
	msg2.field_of_view = 0.26;
	msg2.min_range = 0.1;
	msg2.max_range = 5;

	sensor_msgs::Range msg3;
	std_msgs::Header header3;
	header3.stamp = ros::Time::now();
	header3.frame_id = "/h_ultrasound";
	msg3.header = header3;
	msg3.radiation_type = 0;
	msg3.field_of_view = 0.26;
	msg3.min_range = 0.1;
	msg3.max_range = 5;
	
	sensor_msgs::Range msg4;
	std_msgs::Header header4;
	header4.stamp = ros::Time::now();
	header4.frame_id = "/IR_left";
	msg4.header = header4;
	msg4.radiation_type = 1;
	msg4.field_of_view = 0.26;
	msg4.min_range = 0.1;	
	msg4.max_range = 5;

	sensor_msgs::Range msg5;
	std_msgs::Header header5;
	header5.stamp = ros::Time::now();
	header5.frame_id = "/IR_right";
	msg5.header = header5;
	msg.radiation_type = 1;
	msg5.field_of_view = 0.26;
	msg5.min_range = 0.1;
	msg5.max_range = 5;

	msg.range = u_left;//rand()%3;
	ultrasound_pub.publish(msg);

	msg1.range = u_right;//rand()%3;
	ultrasound_pub1.publish(msg1);

	msg2.range = u_q;//rand()%3;
	ultrasound_pub2.publish(msg2);

	msg3.range = u_h;//rand()%3;
	ultrasound_pub3.publish(msg3);

	msg4.range = 2;//rand()%3;
	ultrasound_pub4.publish(msg4);

	msg5.range = 2;//rand()%3;
	ultrasound_pub5.publish(msg5);

	cout<<"发送完毕"<<endl;
}

int main1(int argc, char **argv)
{ 
	ros::init(argc, argv, "talkerUltraSound");
	ros::NodeHandle n;
	ros::Subscriber  sub = n.subscribe("/sensor", 10, SubCallback);
	while(1)
	{
		if(u_q<0.5)
		{
			//停止当前所有运动指令
			//stop();
			while(u_q>0.5)
			{
			}
			//恢复所有运动指令
			//restart();
		}
	}
	ultrasound_pub   = n.advertise<sensor_msgs::Range>("UltraSoundPublisher", 10);
	ultrasound_pub1 = n.advertise<sensor_msgs::Range>("UltraSoundPublisher1", 10);
	ultrasound_pub2 = n.advertise<sensor_msgs::Range>("UltraSoundPublisher2", 10);
	ultrasound_pub3 = n.advertise<sensor_msgs::Range>("UltraSoundPublisher3", 10);
	ultrasound_pub4 = n.advertise<sensor_msgs::Range>("UltraSoundPublisher4", 10);
	ultrasound_pub5 = n.advertise<sensor_msgs::Range>("UltraSoundPublisher5", 10);

	ros::Rate loop_rate(1000);
	int count = 0;

	while (ros::ok())
	{
		ros::spin();
		loop_rate.sleep();
	}
		return 0;
	}


int main(int argc, char **argv)
{
	ros::init(argc, argv, "talkerUltraSound");
	ros::NodeHandle n;
	ros::Subscriber  sub = n.subscribe("/sensor", 10, SubCallback);  
	ros::Rate r(100);
	ultrasound_pub   = n.advertise<sensor_msgs::Range>("UltraSoundPublisher", 10);
	ultrasound_pub1 = n.advertise<sensor_msgs::Range>("UltraSoundPublisher1", 10);
	ultrasound_pub2 = n.advertise<sensor_msgs::Range>("UltraSoundPublisher2", 10);
	ultrasound_pub3 = n.advertise<sensor_msgs::Range>("UltraSoundPublisher3", 10);
	ultrasound_pub4 = n.advertise<sensor_msgs::Range>("UltraSoundPublisher4", 10);
	ultrasound_pub5 = n.advertise<sensor_msgs::Range>("UltraSoundPublisher5", 10);
	ros::spin();
	while(1)
	{
	}
	return 0;
}




