#include "led.h"
#include "STM32F10x.h"
#include "systick.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStucture;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE,ENABLE);
	
	GPIO_InitStucture.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStucture.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStucture.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStucture);
	GPIO_SetBits(GPIOB,GPIO_Pin_5);

  GPIO_InitStucture.GPIO_Pin=GPIO_Pin_5;
	GPIO_Init(GPIOE,&GPIO_InitStucture);
	GPIO_SetBits(GPIOE,GPIO_Pin_5);
}




void LED_Flash(uint16_t num)
{
	static uint32_t lasttick = 0;
	
	if((Sys_GetTick() - lasttick) > num)
	{
		lasttick = Sys_GetTick();
	}
	
	if((Sys_GetTick() - lasttick) > (num / 2))
	{
		GPIOB->BSRR = GPIO_Pin_5;
	}
	else
	{
		GPIOB->BRR = GPIO_Pin_5;
	}
	
}



