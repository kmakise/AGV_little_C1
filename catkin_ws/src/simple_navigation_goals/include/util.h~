#include <iostream>
#include <string.h>
#include <stdexcept>
#include <fstream>
#include <sstream> 
#include<ros/ros.h>
#include <uart.h>
#include <rcv.h>
#include"simple_navigation_goals/msg209.h"
#include"simple_navigation_goals/sensor.h"
#define  GOAL_PATH  "/home/erye/Desktop/goal.txt"
#define  FILENAME     "/home/erye/hand.txt"
#define  NOTARRAY           13579
using namespace std;
simple_navigation_goals::msg209 msg; 
simple_navigation_goals::sensor s_msg;

void odom_my(const char* data,ros::Publisher pub)
{
	float Xlinear   = (float)data[2]/100;
	float Angular  = (float)data[3]/100;
	msg.RXlinear 	 = Xlinear;
	msg.Rangular  = Angular;
	pub.publish(msg);
}

/*******发送传感器请求*******/
void send(Uart uart,int fd)
{
	char send_data[4];
	send_data[0] = 0xff;
	send_data[1] = 0x32;
	send_data[2] = 0x01;
	send_data[3] = 0x3e;
	uart.UART0_Send(fd,send_data,4);
}

/*******************向指定文件中写入数值********************
*函数名称：                  		 	      read_number
*函数功能：               		    将指定文件中的数值写入变量中
*函数参数：							path      : 文件路径
												number: 	变量
												mode    : 数组的个数    
*返回值：								0：读取成功
											   -1：读取失败
**********************************************************/
int read_number(char* number,int mode)
{
	int cs[mode];
	ifstream in(FILENAME,ios::app);
	if(!in.is_open())
	{
		cout << "打开文件失败" << endl;
		cout<<FILENAME<<endl;
		return -1;
	}
	
	if(mode == NOTARRAY)
	{
		in>>*(number);
	}
	else
	{
		for(int i=0;i<mode;i++)
		{
			in>>cs[i];
			number[i] = cs[i];
		}
	}
	return 0;
}





int write_number(char* number,int choose,int write_number)
{
	if(read_number(number,5) == -1)
	{
		return -1;
	}
	number[choose] = write_number;
	ofstream out(FILENAME);
	if(!out.is_open())
	{
		cout << "打开文件失败" << endl;
		cout<<FILENAME<<endl;
		return -1;
	}
	for(int i=0;i<5;i++)
	{
		int n = number[i];
		out<<n<<" ";
	}
	out.close();
	return 0;
}
/****************************************************
*结构体名称:                              send_data
*成员变量:                     		Xlinear:     代表机器人x的线速度
*									Rangular: 代表机器人的角速度                 
****************************************************/
typedef struct
{
	float Xlinear;       //x的线速度
	float Rangular;   //角速度
}send_data;

/*****************************************************
*函数名称:                               read_goal
*功能:                               读取文件中的目标点
*参数:                               number:存储目标的数组
*返回值:                           0:成功
*                  				    -1:失败
*修改时间:                      2018年10月3日  10:38
*修改人:							张嘉皓
*****************************************************/
int read_goal(int* number)
{
	ifstream in("/home/erye/Desktop/goal.txt",ios::app);
	if(!in.is_open())
	{
		cout << "打开文件失败" << endl;
		return -1;
	}
	in>>number[0];
	in>>number[1];
	return 0;
}
/**************************************************
*名称:                                        log
*功能:                                   记录日志
*入口参数:                              speed
*出口参数:                                 无
**************************************************/
/*void log(char* speed)
{
	ofstream file;
	file.open("/home/erye/Desktop/1.txt",ios::app);
	file<<speed<<endl;
	file.close();
}*/


/**************************************************
*名称:                              sensor
*功能:                       解析传感器数据
*入口参数:  	 	             data    
*出口参数:                         无
**************************************************/
void sensor(const char* data,ros::Publisher pub_sensor)
{
//	printf("解析前：USA[%d %d]  USB[%d %d]  USL[%d %d]  USR[%d %d]\n",data[6]&0xff,data[7]&0xff
//	,data[8]&0xff,data[9]&0xff,data[10]&0xff,data[11]&0xff,data[12]&0xff,data[13]&0xff);
	printf("解析前：IR1[%d %d]  IR2[%d %d]\n",data[2]&0xff,data[3]&0xff,data[4]&0xff,data[5]&0xff);
	s_msg.IR0    =  (((data[2]&0xff)<<8)|(data[3]&0xff)&0xffff);
	s_msg.IR1    =  (((data[4]&0xff)<<8)|(data[5]&0xff)&0xffff);
	s_msg.USA  =  (((data[6]&0xff)<<8)|(data[7]&0xff)&0xffff);
	s_msg.USB  =  (((data[8]&0xff)<<8)|(data[9]&0xff)&0xffff);
	s_msg.USL  =  (((data[10]&0xff)<<8)|(data[11]&0xff)&0xffff);
	s_msg.USR  =  (((data[12]&0xff)<<8)|(data[13]&0xff)&0xffff);
//	printf("解析后：USA[%d]  USB[%d]  USL[%d]  USR[%d]\n",s_msg.USA,s_msg.USB,s_msg.USL,s_msg.USR);
	printf("解析后：IR1[%d]  IR2[%d] \n",s_msg.IR0,s_msg.IR1);
	cout<<"------------------------------------------------------------------------------------------------------------------------------"<<endl;
	pub_sensor.publish(s_msg);
}
/*************************************************** 
*名称:                                  analysis_number
*功能:                             将解析到的信息再次解析为4个轮子的速度
*入口参数:                               data             接收到的串口数据
* 												 data_len      数据长度
*出口参数:                           四个轮子的速度
***************************************************/
void analysis_number(char* data,int data_len,ros::Publisher pub,ros::Publisher pub_sensor)
{
	string return_data[4];
	int va_number = 0;
	int number[4];
	int num = 0;
	for(int i=0;i<data_len;i++)
	{	
		if(data[1] == SENSOR_FLAG)
		{
			/*解析传感器函数*/
			sensor(data,pub_sensor);         
			return;
		}
		if(data[1] == ODOM_FLAG)
		{
			odom_my(data,pub);
			return;
		}
	}
}


