/**
  ******************************************************************************
  * @file    conHandle.c
  * @author  张东
  * @version V1.0.0
  * @date    2019-11-7
  * @brief   通信处理
  ******************************************************************************
  */
/*include file ---------------------------------------------------------------*/
#include "comHandle.h"
#include "usart.h"
#include "pidctrller.h"
#include "stdio.h"


/*Golbal data space ----------------------------------------------------------*/
#define UART_COM_STAT   	'<'				//串口通信开始字节
#define UART_COM_END			'>'				//串口通信结束字节


UartBufTypedef g_ComData[3];				//串口接收缓冲区

/* Receive -------------------------------------------------------------------*/

//串口字节流写入到缓冲区
void USART_RxToBuf(uint8_t data,USART_TypeDef* USARTx)
{
	uint8_t cur = 0;
	
	//读取通信端口选择缓冲区
	if(USARTx == USART1)
	{
		cur = 0;
	}
	else if(USARTx == USART2)
	{
		cur = 1;
	}
	else if(USARTx == USART3)
	{
		cur = 2;
	}
	//将数据写入
	
	//上一次消息处理结束
	if(g_ComData[cur].Over == 0)
	{
		//开始
		if(data == UART_COM_STAT )
		{
			//长度清零
			g_ComData[cur].Len = 0;
		}
		//结束
		else if(data == UART_COM_END)
		{
			//接收结束
			g_ComData[cur].Over = 1;
		}
		//数据
		else
		{
			//写入数据
			g_ComData[cur].Buf[g_ComData[cur].Len] = data;
			//移动光标
			g_ComData[cur].Len = (g_ComData[cur].Len + 1) % 100;
		}
	}
}

/* Handle --------------------------------------------------------------------*/

//设定电机速度
void setMotoSpeed(uint8_t * cmd)
{
	//测试暂定协议 <MSXXXSXXX> S速度符号 XXX速度值 毫米每秒
	
	int16_t speed[2] = {0,0};
	
	//左侧速度
	speed[0] = (cmd[2] - 0x30) * 100
						+(cmd[3] - 0x30) * 10
						+(cmd[4] - 0x30);
	
	speed[0] = (cmd[1] == 'A') ? speed[0] : -speed[0];
	
	//右侧速度
	speed[1] = (cmd[6] - 0x30) * 100
						+(cmd[7] - 0x30) * 10
						+(cmd[8] - 0x30);
	
	speed[1] = (cmd[5] == 'A') ? speed[1] : -speed[1];
	
	//设置速度
	SetTargetSpeed(speed[0],speed[0],speed[1],speed[1]);
	
}

//ROS速度指令解析与速度发布
void ROS_SpeedDataSubscribe(uint8_t * cmd)
{
	//通信协议
	//<RSXXXSRRRR> R 标识 S符号+- XXX线速度 mm/s RRR角速度 rad/s * 100
	
	//速度的分解与合成详见图解
	
	//线速度
	float vx =  (cmd[2] - 0x30) * 100
	           +(cmd[3] - 0x30) * 10
	           +(cmd[4] - 0x30);
	
	vx = (cmd[1] == 'A') ? vx : -vx;
	
	//角速度
	float w =  (cmd[6] - 0x30) 
	           +(cmd[7] - 0x30) * 0.1
						 +(cmd[8] - 0x30) * 0.01
						 +(cmd[9] - 0x30) * 0.001;
	
	w = (cmd[5] == 'A') ? w : -w;
	
	//差分底盘合速度各个速度点的的速度分解
	float va = (w * 187.833)/0.891749586;
	
	int16_t speed[4];
	
	speed[0] = vx + va;
	speed[1] = vx + va;
	speed[2] = vx - va;
	speed[3] = vx - va;
	
	SetTargetSpeed(speed[1],speed[0],speed[3],speed[2]);

}

//发送电量信息
void sendBatteryVoltage(uint8_t * cmd)
{
	uint8_t str[50];
	
	float ctv = (cmd[1] - 0x30) * 10 		+ 
							(cmd[2] - 0x30) 				+
							(cmd[3] - 0x30) * 0.1 	+
							(cmd[4] - 0x30) * 0.01	;
	
	float mtv = (cmd[5] - 0x30) * 10 		+ 
							(cmd[6] - 0x30) 				+
							(cmd[7] - 0x30) * 0.1 	+
							(cmd[8] - 0x30) * 0.01	;
	
	sprintf((char*)str,"<V%c%c%c%c%c%c%c%c>",
		cmd[1],cmd[2],cmd[3],cmd[4],cmd[5],cmd[6],cmd[7],cmd[8]);
	
	USART_SendString(USART3,str);
}

//发送检测请求
void sendBatteryVoltageMeasure(uint8_t * cmd)
{
	USART_SendString(USART2,(uint8_t *)"<V>");
}

/* Analysis ------------------------------------------------------------------*/

//ROS数据接收处理
void ROS_RxBufAnalysis(UartBufTypedef * buf)
{
	//完整性被使能
	if(buf->Over == 1)
	{	
		//通信协议
		//开始 ‘<’ 结束 '>'
		//[0] 标识 [n] 数据
		switch(buf->Buf[0])
		{
			case 'M'://移动速度控制 
			{
				setMotoSpeed(buf->Buf);
				break;
			}
			case 'R'://线速度角速度控制模式
			{
				ROS_SpeedDataSubscribe(buf->Buf);
				break;
			}
			case 'V'://发起电量检测请求
			{
				sendBatteryVoltageMeasure(buf->Buf);
				break;
			}
		}
		//清除未完成标志位
		buf->Over = 0;
	}
}

//控制器数据接收处理
void Ctrller_RxBufAnalysis(UartBufTypedef * buf)
{
	//完整性被使能
	if(buf->Over == 1)
	{	
		//通信协议
		//开始 ‘<’ 结束 '>'
		//[0] 标识 [n] 数据
		switch(buf->Buf[0])
		{
			case 'V'://电池组数据
			{
				sendBatteryVoltage(buf->Buf);
				break;
			}
		}
		//清除未完成标志位
		buf->Over = 0;
	}
}

/*Setup and Loop function ----------------------------------------------------*/

//通信处理初始化
void comHandleSetup(void)
{
	//配置串口接收函数
	USART_RxFuncConfig(USART_RxToBuf);
}

//通信处理循环
void comHandleLoop(void)
{
	//接收缓冲区数据解析
	ROS_RxBufAnalysis(&g_ComData[2]);
	ROS_RxBufAnalysis(&g_ComData[0]);
	Ctrller_RxBufAnalysis(&g_ComData[1]);
}


