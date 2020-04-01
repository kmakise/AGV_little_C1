/**
  ******************************************************************************
  * @file    main.c
  * @author  张东
  * @version V1.0.0
  * @date    2019-11-5
  * @brief   移动平台电机驱动与电量检测
  ******************************************************************************
  */
/*include file ---------------------------------------------------------------*/
#include "stm32f10x.h"
#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "pulser.h"
#include "quantity.h"
#include "stdio.h"

/*Golbal data space ----------------------------------------------------------*/

#define UART_COM_STAT   '<'	//串口通信开始字节
#define UART_COM_END		'>'	//串口通信结束字节

UartBufTypedef g_uartComData = {.Over = 0 ,.Len = 0};//串口接收缓冲区

//串口字节流写入到缓冲区
void UsartRxToBuf(uint8_t data)
{
	//上一次消息处理结束
	if(g_uartComData.Over == 0)
	{
		//开始
		if(data == UART_COM_STAT )
		{
			//长度清零
			g_uartComData.Len = 0;
		}
		//结束
		else if(data == UART_COM_END)
		{
			//接收结束
			g_uartComData.Over = 1;
		}
		//数据
		else
		{
			//写入数据
			g_uartComData.Buf[g_uartComData.Len] = data;
			//移动光标
			g_uartComData.Len = (g_uartComData.Len + 1) % 100;
		}
	}
}


//获得电池组电压 0 主控外设电池组 1 动力系统电池组
float getBatteryPackVoltage(uint8_t ch)
{
	switch (ch)
	{
		case 0:
		{
			//读取ADC通道值
			uint16_t adcval = get_adc(ADC_Channel_5);
			//计算ADC通道电压
			float vol = 3.3 * adcval / 4096;
			//分压比计算电池组电压
			vol = vol * 13.1 / 1.1;
			//电阻误差补偿
			vol = vol * 1.0152;
			return vol;
			break;
		}
		case 1:
		{
			//读取ADC通道值
			uint16_t adcval = get_adc(ADC_Channel_4);
			//计算ADC通道电压
			float vol = 3.3 * adcval / 4096;
			//分压比计算电池组电压
			vol = vol * 13.1 / 1.1;
			//电阻误差补偿
			vol = vol * 1.0067;
			return vol; 
			break;
		}
	}
	return 0;
}

//电机功率输出控制
void Pwm_MotorCtrl(uint8_t * cmd)
{
	//解析控制模式
	uint8_t ms1 = cmd[1];
	uint8_t ms2 = cmd[5];
	uint8_t ms3 = cmd[9];
	uint8_t ms4 = cmd[13];
		
	//解析控制数据
	uint16_t pwm1 = (cmd[2] - 0x30) * 100+ 
									(cmd[3] - 0x30) * 10+ 
									(cmd[4] - 0x30);
	
	uint16_t pwm2 = (cmd[6] - 0x30) * 100+ 
									(cmd[7] - 0x30) * 10+ 
									(cmd[8] - 0x30);
	
	uint16_t pwm3 = (cmd[10] - 0x30) * 100+ 
									(cmd[11] - 0x30) * 10+ 
									(cmd[12] - 0x30);
	
	uint16_t pwm4 = (cmd[14] - 0x30) * 100+ 
									(cmd[15] - 0x30) * 10+ 
									(cmd[16] - 0x30);
									
	//设置PWM寄存器
	TIM2->CCR1 = (ms1 == 'A') ? pwm1 : 0;
	TIM2->CCR2 = (ms1 == 'B') ? pwm1 : 0;
	
	TIM2->CCR3 = (ms2 == 'A') ? pwm2 : 0;
	TIM2->CCR4 = (ms2 == 'B') ? pwm2 : 0;
	
	TIM3->CCR1 = (ms3 == 'B') ? pwm3 : 0;
	TIM3->CCR2 = (ms3 == 'A') ? pwm3 : 0;
	
	TIM3->CCR3 = (ms4 == 'B') ? pwm4 : 0;
	TIM3->CCR4 = (ms4 == 'A') ? pwm4 : 0;
	
}

//返回电压值
void Adc_BatteryVoltage(uint8_t * cmd)
{
	uint8_t str[50];
	
	//开始
	str[0] = '<';
	
	//标识
	str[1] = 'V';
	
	//控制电池组电压
	float ctr = getBatteryPackVoltage(0);
	
	str[2] = (uint8_t)(ctr / 10  ) % 10 + 0x30;
	str[3] = (uint8_t)(ctr       ) % 10 + 0x30;
	str[4] = (uint8_t)(ctr * 10  ) % 10 + 0x30;
	str[5] = (uint8_t)(ctr * 100 ) % 10 + 0x30;
	
	//动力电池组电压
	float mtr = getBatteryPackVoltage(1);
	
	str[6] = (uint8_t)(mtr / 10  ) % 10 + 0x30;
	str[7] = (uint8_t)(mtr       ) % 10 + 0x30;
	str[8] = (uint8_t)(mtr * 10  ) % 10 + 0x30;
	str[9] = (uint8_t)(mtr * 100 ) % 10 + 0x30;
	
	//结束
	str[10] = '>';
	
	str[11] = 0;
	
	USART_SendString(USART3,str);
	
}

//消息接收解析
void RxBufAnalysis(UartBufTypedef * buf)
{
	//小完整性被使能
	if(buf->Over == 1)
	{	
		//通信协议
		//开始 ‘<’ 结束 '>'
		//[0] 标识 [n] 数据
		switch(buf->Buf[0])
		{
			case 'M'://电机输出功率控制 <MSXXXSXXXSXXXSXXX> S方向 A，B  XXX功率控制0-1000 
			{
				Pwm_MotorCtrl(buf->Buf);
				break;
			}
			case 'V'://读取电池组数据
			{
				Adc_BatteryVoltage(buf->Buf);
				break;
			}
		}
		//清除未完成标志位
		buf->Over = 0;
	}
}
void led_init(void)
{
	GPIO_InitTypeDef gpio;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	gpio.GPIO_Pin = GPIO_Pin_13;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed  = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOC,&gpio);
}



void led_running(void)
{
	static uint16_t ph,div;
	static _Bool flag;
	div++;
	GPIOC->BSRR = GPIO_Pin_13 << 16 * (ph<div);
	if(div==500)
	{
		div = RESET;
		ph += !flag;
		ph -= flag;
		flag += (ph==500);
		flag *= !(ph==0);
	}
}

/*main function -------------------------------------------------------*/
int main(void)
{		
	//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	//延时初始化
	delay_init();

	//PWM通道初始化
	TIM2_PWM_Init(1000-1,2-1);
	TIM3_PWM_Init(1000-1,2-1); 
	//串口通信初始化
	USART3_Initialise(115200);  
	//配置串口接收函数
	USART_RxFuncConfig(USART3,UsartRxToBuf);
	//LED初始化
	led_init(); 
	//ADC转换初始化
	ADC_Init_quantity();

	while (1)
	{
		//接收消息解析
		RxBufAnalysis(&g_uartComData);
		//LED呼吸灯
		led_running();
	}	 
	return 0;
}


