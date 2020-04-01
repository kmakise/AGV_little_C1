#include <ros/ros.h>  
#include <iostream>
#include <move_base_msgs/MoveBaseAction.h>  
#include <actionlib/client/simple_action_client.h>  
#include </home/kmakise/catkin_ws/src/simple_navigation_goals/include/util.h>
#define GOALPATH "/home/erye/Desktop/goal.txt"
using namespace std;
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;  
  
int read_number(int* number)
{
	ifstream in(GOALPATH,ios::app);
	if(!in.is_open())
	{
		cout<< "打开文件失败" << endl;
		cout<<GOALPATH<<endl;
		return -1;
	}
	
	else
	{
		for(int i=0;i<2;i++)
		{
			in>>number[i];
		}
	}
	return 0;
}

int main(int argc, char** argv){  
  ros::init(argc, argv, "send2goal");  
  
  //tell the action client that we want to spin a thread by default  
  MoveBaseClient ac("move_base", true);  
  
  //wait for the action server to come up 
  while(!ac.waitForServer(ros::Duration(5.0))){  
    ROS_INFO("Waiting for the move_base action server to come up");  
  }  
  
  move_base_msgs::MoveBaseGoal goal;  
  int number[2];
  read_number(number);
  //we'll send a goal to the robot to move 1 meter forward  
  goal.target_pose.header.frame_id = "map";  
  goal.target_pose.header.stamp = ros::Time::now();  
  
  goal.target_pose.pose.position.x = number[0]; //更改前进距离 米 发布自动避障
  goal.target_pose.pose.position.y = number[1]; //更改前进距离 米 发布自动避障
  goal.target_pose.pose.orientation.w = 1.0;  
  
  ROS_INFO("Sending goal");  
  ac.sendGoal(goal);  
  
  ac.waitForResult();  
  
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)  
    ROS_INFO("Hooray, the base moved 1 meter forward");  
  else  
    ROS_INFO("The base failed to move forward 1 meter for some reason");  
  

		ofstream out( "/home/erye/Desktop/goal2send_off.txt");
		if(!out.is_open())
		{
			cout << "打开文件失败" << endl;
			return -1;
		}
		out<<0;
  return 0;  
}  
