/*#include </home/erye/catkin_ws/src/simple_navigation_goals/include/uart.h>
#include </home/erye/catkin_ws/src/simple_navigation_goals/include/util.h>
#include <ros/ros.h>
#include <rcv.h>
#include "simple_navigation_goals/msg209.h"
#define BUFFER_SIZE  35
using namespace std;
Uart uart;
bool switch4data;
bool switch4data1;
int choose;
int result;
extern int parsing(char* arr1,char* arr2,bool* ok1,bool* ok2);
ros::Publisher pub;
 /*****************************************************
*结构体名称:       receive_data
*成员变量:
*        		   			@is_analysis   消息是否处理完
*				   			@data_len      消息长度
*				   			@data             缓冲区
*							@send            是否可以发送
******************************************************/
/*int number1;
int number2; 
typedef struct
{
	char data[BUFFER_SIZE];
	char data1[BUFFER_SIZE];
}receive_data;

receive_data rcv;
void* check(void* ptr)
{
	int fd;                            //文件描述符   
    int len;                          
    int i;
	int err;
    char rcv_buf[1]; 
	void switch_fun();
    fd   = uart.UART0_Open(fd); //打开串口，返回文件描述符  
	err = uart.UART0_Init(fd,115200,0,8,1,'N');  
	while(1)
	{
		len = uart.UART0_Recv(fd, rcv_buf,1);	
		printf("%x ",rcv_buf[0]);
		if(rcv_buf[0] == 0x3e) cout<<endl;
	}
}

void init()
{
	switch4data                 =   true;
	switch4data1               =   false;
	choose 						 =   1;
	number1                     =   0;
	number2                     =   0;
}
int main(int argc, char **argv)
{  
	init();
	
	ros::init(argc,argv,"new_rec");
	ros::NodeHandle nh;	
	pub = nh.advertise<simple_navigation_goals::msg209>("/car_run",10);

	pthread_t id_1;
    int ret1 = pthread_create(&id_1, NULL,check , NULL);
	
	while(1)
	{
	}
	return 0;
}  


/*************************************************华丽的分割线******************************************************/

#include "ros/ros.h"
#include "sensor_msgs/Range.h"
#include "std_msgs/Header.h"
#include <time.h>
#include <sstream>
#include <iostream>
#include <tf/transform_broadcaster.h>
#include"simple_navigation_goals/sensor.h"
using namespace std;
void SubCallback(const simple_navigation_goals::sensor info)  
{
	cout<<"????????????????????????????"<<endl;
	cout<<"IR0:"<<info.IR0<<endl;
	cout<<"IR1:"<<info.IR1<<endl;
	cout<<"USA:"<<info.USA<<endl;
	cout<<"USB:"<<info.USB<<endl;
	cout<<"USL:"<<info.USL<<endl;
	cout<<"USR:"<<info.USR<<endl;
	cout<<"---------------------------------------------------------------------------------------------"<<endl;
}
int main(int argc, char **argv)
{ 
	ros::init(argc, argv, "talkerUltraSound");
	ros::NodeHandle n;
	ros::Publisher ultrasound_pub = n.advertise<sensor_msgs::Range>("UltraSoundPublisher", 10);
	cout<<"-----"<<endl;
	ros::Subscriber odom_sub = n.subscribe("/sensor", 10, SubCallback); 
	ros::spin();
	return 0;
}

