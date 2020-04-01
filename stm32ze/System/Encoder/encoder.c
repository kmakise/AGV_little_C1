/**
  ******************************************************************************
  * @file    main.c
  * @author  张东
  * @version V1.0.0
  * @date    2019-11-7
  * @brief   移动平台定时器编码器配置与编码器的相关操作
  ******************************************************************************
  */
/*include file ---------------------------------------------------------------*/
#include "encoder.h"

void TIM1_EncoderMode(u32 prescaler,u32 period)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_ICInitTypeDef TIM_ICInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);	/* 允许TIM1的时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE | RCC_APB2Periph_AFIO, ENABLE);	/* 使能GPIOB时钟 */
	
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM1,ENABLE);  //TIM1完全重映射

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;		/* 浮空输入 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_11;	/* 第3引脚 */
	GPIO_Init(GPIOE, &GPIO_InitStructure);	/* 初始化GPIOA */

	TIM_DeInit(TIM1);	/* 将定时器2寄存器设为初始值 */

	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);	/* 填入缺省值 */
	TIM_TimeBaseStructure.TIM_Prescaler = prescaler;	/* 预分频值 */
	TIM_TimeBaseStructure.TIM_Period = period;	/* 自动重载值 */
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;	/* 时钟分割 */
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	/* 向上计数 */
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);	/* 初始化定时器2 */

	TIM_EncoderInterfaceConfig(TIM1, TIM_EncoderMode_TI12, TIM_ICPolarity_Falling ,TIM_ICPolarity_Falling);	/* 设置编码器模式 */

	TIM_ICStructInit(&TIM_ICInitStructure);	/* 填入缺省值 */
	TIM_ICInitStructure.TIM_ICFilter = 6;	/* 输入比较滤波器 */
	TIM_ICInit(TIM1, &TIM_ICInitStructure);	/* 初始化定时器2 */

	TIM_SetCounter(TIM1,0);	/* 计数器初始化 */
	TIM_Cmd(TIM1, ENABLE);	/* 开启定时器2 */
}

void TIM2_EncoderMode(u32 prescaler,u32 period)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_ICInitTypeDef TIM_ICInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	/* 允许TIM2的时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);	/* 使能GPIOA时钟 */

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;		/* 浮空输入 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;	/* 第3引脚 */
	GPIO_Init(GPIOA, &GPIO_InitStructure);	/* 初始化GPIOA */

	TIM_DeInit(TIM2);	/* 将定时器2寄存器设为初始值 */

	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);	/* 填入缺省值 */
	TIM_TimeBaseStructure.TIM_Prescaler = prescaler;	/* 预分频值 */
	TIM_TimeBaseStructure.TIM_Period = period;	/* 自动重载值 */
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;	/* 时钟分割 */
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	/* 向上计数 */
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);	/* 初始化定时器2 */

	TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_Falling ,TIM_ICPolarity_Falling);	/* 设置编码器模式 */

	TIM_ICStructInit(&TIM_ICInitStructure);	/* 填入缺省值 */
	TIM_ICInitStructure.TIM_ICFilter = 6;	/* 输入比较滤波器 */
	TIM_ICInit(TIM2, &TIM_ICInitStructure);	/* 初始化定时器2 */

	TIM_SetCounter(TIM2, 0);	/* 计数器初始化 */
	TIM_Cmd(TIM2, ENABLE);	/* 开启定时器2 */
}
void TIM3_EncoderMode(u32 prescaler,u32 period)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_ICInitTypeDef TIM_ICInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	/* 允许TIM3的时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);	/* 使能GPIOA时钟 */

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;		/* 浮空输入 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;	/* 第3引脚 */
	GPIO_Init(GPIOA, &GPIO_InitStructure);	/* 初始化GPIOA */

	TIM_DeInit(TIM3);	/* 将定时器2寄存器设为初始值 */

	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);	/* 填入缺省值 */
	TIM_TimeBaseStructure.TIM_Prescaler = prescaler;	/* 预分频值 */
	TIM_TimeBaseStructure.TIM_Period = period;	/* 自动重载值 */
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;	/* 时钟分割 */
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	/* 向上计数 */
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);	/* 初始化定时器2 */

	TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Falling ,TIM_ICPolarity_Falling);	/* 设置编码器模式 */

	TIM_ICStructInit(&TIM_ICInitStructure);	/* 填入缺省值 */
	TIM_ICInitStructure.TIM_ICFilter = 6;	/* 输入比较滤波器 */
	TIM_ICInit(TIM3, &TIM_ICInitStructure);	/* 初始化定时器2 */

	TIM_SetCounter(TIM3, 0);	/* 计数器初始化 */
	TIM_Cmd(TIM3, ENABLE);	/* 开启定时器2 */
}
void TIM4_EncoderMode(u32 prescaler,u32 period)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_ICInitTypeDef TIM_ICInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);	/* 允许TIM4的时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);	/* 使能GPIOA时钟 */

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;		/* 浮空输入 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;	/* 第3引脚 */
	GPIO_Init(GPIOB, &GPIO_InitStructure);	/* 初始化GPIOA */

	TIM_DeInit(TIM4);	/* 将定时器2寄存器设为初始值 */

	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);	/* 填入缺省值 */
	TIM_TimeBaseStructure.TIM_Prescaler = prescaler;	/* 预分频值 */
	TIM_TimeBaseStructure.TIM_Period = period;	/* 自动重载值 */
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;	/* 时钟分割 */
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	/* 向上计数 */
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);	/* 初始化定时器2 */

	TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_Falling ,TIM_ICPolarity_Falling);	/* 设置编码器模式 */

	TIM_ICStructInit(&TIM_ICInitStructure);	/* 填入缺省值 */
	TIM_ICInitStructure.TIM_ICFilter = 6;	/* 输入比较滤波器 */
	TIM_ICInit(TIM4, &TIM_ICInitStructure);	/* 初始化定时器2 */

	TIM_SetCounter(TIM4, 0);	/* 计数器初始化 */
	TIM_Cmd(TIM4, ENABLE);	/* 开启定时器2 */
}


