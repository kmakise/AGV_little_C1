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
#include "pidctrller.h"
#include "usart.h"
#include "stdio.h"
/*Golbal data space ----------------------------------------------------------*/
#define MOTOR_OUTPUT_MAX					999
#define MOTOR_SPEED_PID_KP				2.400
#define MOTOR_SPEED_PID_KI				1.000
#define MOTOR_SPEED_PID_KD				0.000
#define PI												3.1415926535897932384626433832795

const PIDParamBaseTypedef PARAM_PID = {//电机pid速度控制参数

	.kp = MOTOR_SPEED_PID_KP,				//比例权重
	.ki = MOTOR_SPEED_PID_KI,				//积分权重
	.kd = MOTOR_SPEED_PID_KD,				//微分权重
};

float g_TargetSpeed[4]	 = {0,0,0,0};//目的速度
float g_MotorSpeed[4]	 = {0,0,0,0};//当前速度

 /*
	*电机编号与编码器对应外设：
	*								  /\
  *								 /__\
	*						 _____________
	*	M4 TIM2||=|							|=|| M2 TIM4
	*						|							|
	*				L 	|			 x			|	  R
	*						|							|
	*	M3 TIM3||=|_____________|=|| M1 TIM1
	*
	*	电机减速比			：80:1
	* 编码器分辨率		：2
	* 轮半径					：66mm
	* 短轴距					：170mm
	* 长轴距					：335mm
	* 轮线速度单位		：毫米每秒
	* 轮角速度				：弧度每秒
	*/

//速度值更新
void updataSpeed(void)
{
	int16_t etr[4];
	
	//获得编码器值
	etr[0] = TIM1->CNT;//M1
	TIM1->CNT = 0;
	etr[1] = TIM4->CNT;//M2
	TIM4->CNT = 0;
	etr[2] = TIM3->CNT;//M3
	TIM3->CNT = 0;
	etr[3] = TIM2->CNT;//M4
	TIM2->CNT = 0;
	
	for(int i = 0;i < 4;i++)
	{
		float etrtemp = 0;
		
		//编码器脉冲计算轮角速度
		//360度常量 2*80 = 160t
		etrtemp = ((float)(etr[i] % 30000)) / (2.0 * 80.0);
		//角速度计算轮线速度
		etrtemp = etrtemp * (66 * PI);
		//写入线速度到全局
		g_MotorSpeed[i] = etrtemp * 10.0 * 0.25;
	}
}

//设定目的速度
void SetTargetSpeed(int16_t s1,int16_t s2,int16_t s3,int16_t s4)
{
	g_TargetSpeed[0] = s1;
	g_TargetSpeed[1] = s2;
	g_TargetSpeed[2] = s3;
	g_TargetSpeed[3] = s4;
}

//设定输出脉宽
void setMotorPWM(int16_t s1,int16_t s2,int16_t s3,int16_t s4)
{
	uint8_t str[20];
	
	//开始
	str[0] = '<';
	
	//标志
	str[1] = 'M';
	
	//电机1
	str[2] = (s1 > 0) ? 'A' : 'B';
	s1 = (s1 >= 0) ? s1 : -s1;
	str[3] = s1 /100 % 10 + 0x30;
	str[4] = s1 /10 % 10 + 0x30;
	str[5] = s1 % 10 + 0x30;
	
	//电机2
	str[6] = (s2 > 0) ? 'A' : 'B';
	s2 = (s2 >= 0) ? s2 : -s2;
	str[7] = s2 /100 % 10 + 0x30;
	str[8] = s2 /10 % 10 + 0x30;
	str[9] = s2 % 10 + 0x30;
	
	//电机3
	str[10] = (s3 > 0) ? 'A' : 'B';
	s3 = (s3 >= 0) ? s3 : -s3;
	str[11] = s3 /100 % 10 + 0x30;
	str[12] = s3 /10 % 10 + 0x30;
	str[13] = s3 % 10 + 0x30;
	
	//电机4
	str[14] = (s4 > 0) ? 'A' : 'B';
	s4 = (s4 >= 0) ? s4 : -s4;
	str[15] = s4 /100 % 10 + 0x30;
	str[16] = s4 /10 % 10 + 0x30;
	str[17] = s4 % 10 + 0x30;
	
	//结束
	str[18] = '>';
	str[19] = 0;
	
	//发送PWM数据到电机驱动控制器
	USART_SendString(USART2,str);
}

//上传速度值
void sendUpMotorSpeed(void)
{
	uint8_t str[500];
	//sprintf((char *)str,"%03.2f,%03.2f,%03.2f,%03.2f\r\n",g_MotorSpeed[0],g_MotorSpeed[1],g_MotorSpeed[2],g_MotorSpeed[3]);
	
	//速度的分解与合成详见图解
	
	//分速度的合成
	float Vx = (((g_MotorSpeed[0] + g_MotorSpeed[2]) / 2) + 
						  ((g_MotorSpeed[1] + g_MotorSpeed[3]) / 2) ) / 2;
	
	float Vw = ((((g_MotorSpeed[0] - g_MotorSpeed[2]) / 2) * 0.891749586 / 187.833) + 
						  (((g_MotorSpeed[1] - g_MotorSpeed[3]) / 2) * 0.891749586 / 187.833)) / 2;
	
	uint8_t Syx,Syw;
	
	Syx = (Vx >= 0) ? 'A':'B';
	Syw = (Vw >= 0) ? 'A':'B';
	
	Vx = (Vx >= 0) ? Vx : -Vx;
	Vw = (Vw >= 0) ? Vw : -Vw;
	
	
	uint16_t vxi = Vx ;
	uint16_t vwi = Vw * 1000;
	
	
	sprintf((char *)str,"<S%c%03d,%c%04d>\r\n",Syx,vxi,Syw,vwi);
	
	if(g_MotorSpeed[0] != 0)
	{
		USART_SendString(USART3,str);
	}
	USART_SendString(USART1,str);
}

/**
  * @brief  MotorSpeedPidCtrl.
  * @note		PWM动态函数采用算法“位置式离散比例积分微分方程”
  *         Out = Kp[e(k)]+ki∑e(k)+Kd[e(k)-2e(k-1)+e(k-2)]
  *         其中积分项和微分项受大扰动误差阀值范围生效标志位控制
  * @retval None
  */
void MotorSpeedPidCtrl(void)
{
	static PIDDateBaseTypedef pid[4] = {
		[0].de	= 0,	[1].de	= 0,	[2].de	= 0,	[3].de	= 0,	
		[0].fe	= 0,  [1].fe	= 0,  [2].fe	= 0,  [3].fe	= 0, 
		[0].de1 = 0,  [1].de1 = 0,  [2].de1 = 0,  [3].de1 = 0, 
		[0].de2 = 0,  [1].de2 = 0,  [2].de2 = 0,  [3].de2 = 0, 
		[0].out = 0,  [1].out = 0,  [2].out = 0,  [3].out = 0, 
	};
	
	//进行PID控制计算
	for(int i = 0;i < 4;i++)
	{
		//计算当前误差并移动历史误差
		pid[i].de2	=  pid[i].de1;
		pid[i].de1	=  pid[i].de;
		pid[i].de		=  g_TargetSpeed[i] - g_MotorSpeed[i];
		pid[i].fe	 +=  pid[i].de;
		//pid[i]控制器核心方程
		pid[i].out = 	PARAM_PID.kp * pid[i].de 	+ 
									PARAM_PID.ki * pid[i].fe 	+ 
									PARAM_PID.kd * ( pid[i].de - 2 * pid[i].de1		+ pid[i].de2) * (pid[i].de < 100);
		//输出限制幅度
		pid[i].out = (pid[i].out > MOTOR_OUTPUT_MAX) ? MOTOR_OUTPUT_MAX : pid[i].out;
		pid[i].out = (pid[i].out <-MOTOR_OUTPUT_MAX) ?-MOTOR_OUTPUT_MAX : pid[i].out;
		
		//输出死区限制
		
		
	}
	//输出到电机控制
	setMotorPWM(pid[0].out,pid[1].out,pid[2].out,pid[3].out);
	
	
	//uint8_t str[50];
	//sprintf((char *)str,"%d,%d,%d,%d\r\n",pid[0].out,pid[1].out,pid[2].out,pid[3].out);
	//USART_SendString(USART1,str);
}

//pid控制器执行周期分频器
void PID_Divider(void)
{
	static uint32_t div = 0;
	div++;
	if(div >= 100)
	{
		div = 0;
		//更新当前速度
		updataSpeed();
		//上传速度信息
		sendUpMotorSpeed();
		//执行电机PID控制器
		MotorSpeedPidCtrl();
	}
}








