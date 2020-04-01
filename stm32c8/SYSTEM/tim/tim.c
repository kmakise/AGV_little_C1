#include "tim.h"

void TIM3_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;	
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //时钟使能	
	
	TIM_TimeBaseStructure.TIM_Period = arr; //自动重装寄存器的周期值
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//设置时钟分割
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;//TIM向上记数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);//根据指定的参数初始化TIMx的时间基数单位
 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE );// 使能指定TIM3中断，允许更新中断
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //抢占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  //从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure); //初始化NVIC寄存器

	TIM_Cmd(TIM3, ENABLE); //使能定时器3 
}

void TIM3_IRQHandler(void)  
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //检查TIM3更新中断发生与否
		{
			TIM_ClearITPendingBit(TIM3, TIM_IT_Update  ); //清除TIMx更新中断标志					
			
			 UartRxMonitor(1);  //串口接收监控			
		}		
}




