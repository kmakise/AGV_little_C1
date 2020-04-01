/**
*
* ━━━━━━神兽出没━━━━━━
* 　　 ┏┓     ┏┓
* 　　┏┛┻━━━━━┛┻┓
* 　　┃　　　　　 ┃
* 　　┃　　━　　　┃
* 　　┃　┳┛　┗┳  ┃
* 　　┃　　　　　 ┃
* 　　┃　　┻　　　┃
* 　　┃　　　　　 ┃
* 　　┗━┓　　　┏━┛　Code is far away from bug with the animal protecting
* 　　　 ┃　　　┃        神兽保佑,代码无bug
* 　　　　┃　　　┃
* 　　　　┃　　　┗━━━┓
* 　　　　┃　　　　　　┣┓
* 　　　　┃　　　　　　┏┛
* 　　　　┗┓┓┏━┳┓┏┛
* 　　　　 ┃┫┫ ┃┫┫
* 　　　　 ┗┻┛ ┗┻┛
*
* ━━━━━━感觉萌萌哒━━━━━━
*/



/**
 * 　　　　　　　 ┏┓　　　┏┓
 * 　　　　　　　┏┛┻━━━━━┛┻┓
 * 　　　　　　　┃　　　　　  ┃ 　
 * 　　　　　　　┃　	    ━　　 ┃
 * 　　　　　　　┃　＞　　＜　 ┃
 * 　　　　　　　┃　　　　　　 ┃
 * 　　　　　　　┃     ... ⌒ ...      ┃
 * 　　　　　　　┃　　　　　  ┃
 * 　　　　　　　┗━┓　　　┏━┛
 * 　　　　　　　　 ┃　　　┃　Code is far away from bug with the animal protecting　　　　　　　　　　
 * 　　　　　　　　 ┃　　　┃   神兽保佑,代码无bug
 * 　　　　　　　　 ┃　　　┃　　　　　　　　　　　
 * 　　　　　　　　 ┃　　　┃  　　　　　　
 * 　　　　　　　　 ┃　　　┃
 * 　　　　　　　　 ┃　　　┃　　　　　　　　　　　
 * 　　　　　　　　 ┃　　　┗━━━┓
 * 　　　　　　　　 ┃　　　　　　　┣┓
 * 　　　　　　　　 ┃　　　　　　　┏┛
 * 　　　　　　　　 ┗┓┓┏━┳┓┏┛
 * 　　　　　　　　　┃┫┫　┃┫┫
 * 　　　　　　　　　┗┻┛　┗┻┛
 */

/**
 *　　　　　　　 ┏┓　 ┏┓+ +
 *　　　　　　　┏┛┻━━━┛┻┓ + +
 *　　　　　　　┃　　　　　　┃ 　
 *　　　　　　　┃　　　━　　 ┃ ++ + + +
 *　　　　　　 ████━████      ┃+
 *　　　　　　　┃　　　　　　　┃ +
 *　　　　　　　┃　　　┻　　　┃
 *　　　　　　　┃　　　　　　┃ + +
 *　　　　　　　┗━┓　　　┏━┛
 *　　　　　　　　 ┃　　　┃　　　　　　　　　　　
 *　　　　　　　　 ┃　　　┃ + + + +
 *　　　　　　　　 ┃　　　┃　　　　Code is far away from bug with the animal protecting　　　　　　　
 *　　　　　　　　 ┃　　　┃ + 　　　　神兽保佑,代码无bug　　
 *　　　　　　　　 ┃　　　┃
 *　　　　　　　　 ┃　　　┃　　+　　　　　　　　　
 *　　　　　　　　 ┃　 　 ┗━━━┓ + +
 *　　　　　　　　 ┃ 　　　　   ┣┓
 *　　　　　　　　 ┃ 　　　　　 ┏┛
 *　　　　　　　　 ┗┓┓┏━┳┓┏┛ + + + +
 *　　　　　　　　  ┃┫┫ ┃┫┫
 *　　　　　　　　  ┗┻┛ ┗┻┛+ + + +
 */




#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;


/*************************宏定义******************************/
#define   HEAD                      0xffffffff       //   协议头     maybe is error
#define   END                        0x3e            //   协议尾
#define   ODOM_FLAG          0x01            //   里程计标志位
#define   SENSOR_FLAG       0x32            //   传感器标志位
#define   ODOM_SIZE           5                 //   里程计协议长度
#define   SENSOR_SIZE        17               //    传感器协议长度
#define   COMPLETE             0                //    表示当前缓冲区解析完毕
#define   ERROR                   -1               //    表示协议不合法
#define   SUCCESS                1                //    表示协议解析完成     
#define   ISERROR                404            //    表示数组为空
#define   SENSOR_ERROR    -2				//     表示传感器通信数据丢失
/*************************宏定义******************************/

/*------------------------------------------------------------------------------分界线------------------------------------------------------------------------------*/

/*************************结构体******************************/
/*struct temporary
{
	char* buf;       //临时缓冲区
	int*    sub;		 //缓冲区的当前下标
};
/*************************结构体******************************/

/*------------------------------------------------------------------------------分界线------------------------------------------------------------------------------*/

/***********************************************函数声明**********************************************/

int find_header(char* agreement_buf,int* begin,int buf_size);

int analysis_buffer(char* agreement_buf,int* begin,int buf_size,char* publish_msg);

int save2temporary_buf(int* temp_sub,char* temp_buf,const char* agreement_buf,int agreement_buf_sub,int agreement_size,int* half);

int link2temporary_buf(int* temp_sub,char* temp_buf,const char* agreement_buf,int* agreement_buf_sub,int agreement_size,int* half,char* publish_msg);

int check_legal(char* agreement,int size,char* publish_msg);

int check_legal(char* agreement,int size);

/***********************************************函数声明**********************************************/

