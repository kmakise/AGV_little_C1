#include <ros/ros.h>
#include <iostream>
#include <unistd.h> 
#include<nav_msgs/Odometry.h>  
#include </home/kmakise/catkin_ws/src/simple_navigation_goals/include/util.h>
#include"simple_navigation_goals/msg209.h"
using namespace std;
float time_flag;
//宏定义
#define FALSE  -1  
#define TRUE   0  

Uart uart;
simple_navigation_goals::msg209 msg1; 
//FILE* log;
ros::Publisher pub;
int fd;
void delay(int i)
{
	int x,y,z;
	for(x = 0;x < i;x++)
		for(y = 10000; y > 0;y--)
			for(z = 50; z >0;z--);
}

void receive(const geometry_msgs::Twist& cmd_vel)
{
/**************************************************临时数据**************************************************/
	cout<<cmd_vel.linear.x<<"---"<<cmd_vel.angular.z<<endl;
	
/**************************************************临时数据**************************************************/


	char send_data[5];
	send_data[0] = 0xff;
	send_data[1] = 0x31;
	send_data[2] = cmd_vel.linear.x * 100.0 ; 
	send_data[3] = cmd_vel.angular.z * 100.0 ;
	send_data[4] = 0x3e;
	printf("%x  %x  %d  %d  %x\n",send_data[0],send_data[1],send_data[2],send_data[3],send_data[4]);
	uart.UART0_Send(fd,send_data,5);
	delay(10);
} 


int main(int argc,char** argv)
{
	ros::init(argc,argv,"receive_cmd");
	ros::NodeHandle nh;
    int err;                           //返回调用函数的状态  
    int len;                          
    int i;  
    char rcv_buf[2];         
    fd = uart.UART0_Open(fd); //打开串口，返回文件描述符  
	err = uart.UART0_Init(fd,115200,0,8,1,'N');  
	pub = nh.advertise<simple_navigation_goals::msg209>("/car_run",10);
	ros::Subscriber sub = nh.subscribe("/cmd_vel",10,receive);
	ros::spin();
	return 0;
}
