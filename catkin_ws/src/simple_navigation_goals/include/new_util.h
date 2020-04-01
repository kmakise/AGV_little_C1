#include <iostream>
#include <string.h>
#include <stdexcept>
#include <sstream> 
#include<ros/ros.h>
#include"simple_navigation_goals/msg209.h"
using namespace std;
simple_navigation_goals::msg209 msg;
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
/*************************************************** 
*名称:                               		  string2int
*功能:                              将字符串转换成数字
*入口参数:                                 number
*出口参数:                        返回转换好的参数
***************************************************/
int string2int(char number)
{
	int return_number;
	stringstream ss;
	ss<<number;
	ss>>return_number;
	if(return_number == 1)
	{
		return 1;
	}
	if(return_number == 2)
	{
		return -1;
	}
	else
	{
		printf("非法协议！已强制退出！请检查正负号协议是否出现异常！\n");
		exit(0);
	}
}
/*************************************************** 
*名称:                               		  string2float
*功能:                              将字符串转换成数字
*入口参数:                                 number
*出口参数:                        返回转换好的参数
***************************************************/
float string2float(string number)
{
	float return_number;
	stringstream ss;
	ss<<number;
	ss>>return_number;
   	return return_number;
}       

/**************************************************
*名称:                                clear_array
*功能:                                 清空数组
*入口参数:                               arr
*出口参数:                               无
**************************************************/
void clear_array(char* arr)
{
	for(int  i=0;i<strlen(arr);i++)
	{
		arr[i] = '\0'; 
	}
}
/*************************************************** 
*名称:                                  analysis_number
*功能:                             将解析到的信息再次解析为4个轮子的速度
*入口参数:                               data             接收到的串口数据
* 												 data_len      数据长度
*出口参数:                           四个轮子的速度
***************************************************/
void analysis_number(char* data,int data_len,send_data* sd,ros::Publisher pub)
{
	string return_data[4];
	int va_number = 0;
	int number[4];
	int num = 0;
	//static char* number = (char*)malloc(sizeof(char)*10);
	for(int i=0;i<data_len;i++)
	{	
		if(data[i]=='v'&&data[i+1]=='a'&&data[i+2]==':')
		{
			int va_num = i+3;
			while(1)
			{
				if(data[va_num]=='d') break;
				return_data[va_number] += data[va_num];
				va_num++;
			}
			va_number++;
		}
		if(data[i] == '>')
		{
			for(int j = i-4;j<i;j++)
			{
				number[num] = string2int(data[j]);
				num++;
			}
		}
	}
	float va[4];				//存储转换后的速度
	if(va_number !=4)
	{
		printf("速度解析异常！已强制退出！错误位置:---------->util.h  第112行  va_number = %d！\n",va_number);
		exit(0);
	}	
	if(0)
	{
		printf("正负号解析异常！已强制退出！错误位置:---------->util.h  第117行  va_number = %d！\n",va_number);
		exit(0);
	}
	for(int i =0;i<4;i++)
	{
		va[i] = string2float(return_data[i])*number[i];
		//return_data[i] = ""; //清除缓存
	}	
	
	msg.RXlinear 	     = ((((va[0] + va[1] + va[2] + va[3])/4)/360)*47.123)/100;
	msg.Rangular      = (((((va[0] + va[1] - va[2] - va[3]) /4)/0.4)/360)*47.123)/100;
	//sd->number = number;	
	//cout<<"Xlinear ["<<msg.RXlinear<<"]   Rangular["<<msg.Rangular<<"]<----------------------->"<<number<<endl;
	pub.publish(msg);
	//return sd;
}

void send_odom(char* data,int data_len,send_data* sd,ros::Publisher pub)
{
	
	for(int i=0;i<data_len;i++)
	{
		printf("%2x   ",data[i]);
	}
	printf("\n");
	if(1)//data[0] == 0xffffffff && data[1] == 0x01 && data[4] == 0x3e)
	{
		//printf("RXlinear %x     ",data[2]);
		//printf("Rangular %x  \n",data[3]);
		msg.RXlinear  = (float)(data[2]/100.00);  //乘0.9
		msg.Rangular = (float)(data[3]/100.00);  //乘0.9
		pub.publish(msg);
	}
	else
	{
		
//
//                         			      _ooOoo_
//                   			        o8888888o
//                            			  88" . "88
//                   	       			   (| -_- |)
//                     	    			  O\  =  /O
//                   			      ____/`---'\____
//                 	      		   	  .'  \\|     |//  `.
//                  			  /  \\|||  :  |||//  \
//           			       /  _||||| -:- |||||-  \
//        			 	          |   | \\\  -  /// |   |
//               			      | \_|  ''\---/''  |   |
//                   		     \  .-\__  `-`  ___/-. /
//                 		       ___`. .'  /--.--\  `. . __
//           			."" '<  `.___\_<|>_/___.'  >'"".
//        			    | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         			      \  \ `-.   \_ __\ /__ _/   .-` /  /
// 	       ======`-.____`-.___\_____/___.-`____.-'======
//          			                   `=---='
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//                 		     佛祖保佑       永无BUG

		printf("非法协议！程序已强制退出！请检查解析过程是否出错！\n");//佛祖保佑，这行用不上，用不上，用不上，用不上。。。。。。
		exit(0);
	}
}

