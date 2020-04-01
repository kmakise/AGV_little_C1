#include "stm32f10x.h"
#include "pulser.h"
/***********************************************************************************************************/
//	
//										TIM2 3 4 PWM输出配置
//
/***********************************************************************************************************/
void TIM2_PWM_Init(u16 arr,u16 psc)
{  
  GPIO_InitTypeDef         GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef        TIM_OCInitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);// 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);   											//使能GPIO外设时钟使能                                                                                                                                                    
																																							  //设置该引脚为复用输出功能,输出TIM1 CH1的PWM脉冲波形
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3; 		//TIM_CH1234
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 													  //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);


	TIM_TimeBaseStructure.TIM_Period = arr; 																		  //设置在下一个更新事件装入活动的自动重装载寄存器周期的值    
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 																		//设置用来作为TIMx时钟频率除数的预分频值  不分频
	TIM_TimeBaseStructure.TIM_ClockDivision =0; 																	//设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  									//TIM向上计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); 															//根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
																																								//TIM3通通道一
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; 														//选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState= TIM_OutputState_Enable; 									//比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; 																						//设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; 											//输出极性:TIM输出比较极性低
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);  																		//根据TIM_OCInitStruct中指定的参数初始化外设TIMx
																																							
  TIM_OCInitStructure.TIM_OutputState =TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;
  TIM_OC2Init(TIM2, &TIM_OCInitStructure);
  TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
																																							
  TIM_OCInitStructure.TIM_OutputState =TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;
  TIM_OC3Init(TIM2, &TIM_OCInitStructure);
  TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);
																																							
  TIM_OCInitStructure.TIM_OutputState =TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;
  TIM_OC4Init(TIM2, &TIM_OCInitStructure);
  TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);

  TIM_CtrlPWMOutputs(TIM2,ENABLE);        																			//MOE 主输出使能        
  TIM_ARRPreloadConfig(TIM2, ENABLE); 																					//使能TIMx在ARR上的预装载寄存器
  TIM_Cmd(TIM2, ENABLE);  																											//使能TIM2
}



void TIM3_PWM_Init(u16 arr,u16 psc)
{  
  GPIO_InitTypeDef         GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef        TIM_OCInitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);// 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB , ENABLE);   //使能GPIO外设时钟使能
                                                                                                                                                                
																																							  //设置该引脚为复用输出功能,输出TIM1 CH1的PWM脉冲波形
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7 ; 											  //TIM_CH12
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 														  //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1 ; 											  //TIM_CH34
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  														  //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	TIM_TimeBaseStructure.TIM_Period = arr; 																		  //设置在下一个更新事件装入活动的自动重装载寄存器周期的值    
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 																		//设置用来作为TIMx时钟频率除数的预分频值  不分频
	TIM_TimeBaseStructure.TIM_ClockDivision =0; 																	//设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  									//TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); 															//根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
																																								//TIM3通通道一
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; 														//选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState= TIM_OutputState_Enable; 									//比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; 																						//设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; 											//输出极性:TIM输出比较极性低
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);  																		//根据TIM_OCInitStruct中指定的参数初始化外设TIMx
																																								//TIM3通道二
  TIM_OCInitStructure.TIM_OutputState =TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;
  TIM_OC2Init(TIM3, &TIM_OCInitStructure);
  TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
																																								//TIM3通道三
  TIM_OCInitStructure.TIM_OutputState =TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;
  TIM_OC3Init(TIM3, &TIM_OCInitStructure);
  TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
																																								//TIM3通道四
  TIM_OCInitStructure.TIM_OutputState =TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;
  TIM_OC4Init(TIM3, &TIM_OCInitStructure);
  TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);

  TIM_CtrlPWMOutputs(TIM3,ENABLE);        																			//MOE 主输出使能        
  TIM_ARRPreloadConfig(TIM3, ENABLE); 																					//使能TIMx在ARR上的预装载寄存器
  TIM_Cmd(TIM3, ENABLE);  																											//使能TIM3
}
void TIM4_PWM_Init(u16 arr,u16 psc)
{  
  GPIO_InitTypeDef         GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef        TIM_OCInitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);												
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  												//使能GPIO外设时钟使能
                                                                                                                                                                
																																								//设置该引脚为复用输出功能,输出TIM1 CH1的PWM脉冲波形
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9 ; 	//TIM_CH1 2 3 4 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  															//复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	TIM_TimeBaseStructure.TIM_Period = arr; 																			//设置在下一个更新事件装入活动的自动重装载寄存器周期的值    
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 																		//设置用来作为TIMx时钟频率除数的预分频值  不分频
	TIM_TimeBaseStructure.TIM_ClockDivision =0; 																	//设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  									//TIM向上计数模式
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); 															//根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
																																								//TIM4通通道一
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; 														//选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState= TIM_OutputState_Enable; 									//比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; 																					//设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; 											//输出极性:TIM输出比较极性低
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);  																		//根据TIM_OCInitStruct中指定的参数初始化外设TIMx
																																								//TIM4通道二
  TIM_OCInitStructure.TIM_OutputState =TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;
  TIM_OC2Init(TIM4, &TIM_OCInitStructure);
  TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
																																								//TIM4通道三
  TIM_OCInitStructure.TIM_OutputState =TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;
  TIM_OC3Init(TIM4, &TIM_OCInitStructure);
  TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);
																																								//TIM4通道四
  TIM_OCInitStructure.TIM_OutputState =TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;
  TIM_OC4Init(TIM4, &TIM_OCInitStructure);
  TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);

  TIM_CtrlPWMOutputs(TIM4,ENABLE);       																			  //MOE 主输出使能        
  TIM_ARRPreloadConfig(TIM4, ENABLE); 																			 	  //使能TIMx在ARR上的预装载寄存器
  TIM_Cmd(TIM4, ENABLE);  																										  //使能TIM4
}

