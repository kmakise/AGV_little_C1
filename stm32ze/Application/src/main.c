/**
  ******************************************************************************
  * @file    main.c
  * @author  张东
  * @version V1.0.0
  * @date    2019-11-7
  * @brief   移动平台下位主程序
  ******************************************************************************
  */

/*include file ---------------------------------------------------------------*/
#include "stm32f10x.h"
#include "encoder.h"
#include "systick.h"
#include "usart.h"
#include "LED.h"
#include "pidctrller.h"
#include "comHandle.h"
#include "syn7318.h"
/*Golbal data space ----------------------------------------------------------*/
uint16_t g_ledflashfreq = 100;


int main(void)
{  
	//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	
	//系统Systick初始化
	Systick_init();
	
	//状态LED初始化
	LED_Init();
	
	//定时器编码器初始化
	TIM1_EncoderMode(0,65535);
	TIM2_EncoderMode(0,65535);
	TIM3_EncoderMode(0,65535);
	TIM4_EncoderMode(0,65535);
	
	//串口初始化
	USART1_Initialise(115200);
	USART2_Initialise(115200);
	USART3_Initialise(115200);
	USART4_Initialise(115200);
	
	//创建中断执行任务
	creatIRQFunc(PID_Divider);
	
	//通信处理初始化
	comHandleSetup();
	
	/*测试*/
	syntest();
	
	while(1)
	{
		//通信数据处理
		comHandleLoop();
		//LED状态闪烁
		LED_Flash(g_ledflashfreq);
		//音频输出
		SoundLoop();
	}
	return 0;
}
