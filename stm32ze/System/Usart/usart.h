#ifndef __USART_H
#define __USART_H
#include "stm32f10x.h"
typedef struct
{
	uint8_t Buf[100];	//串口接收缓冲区
	uint8_t Over;			//串口接收检查
	uint8_t Len;			//串口接收长度
}UartBufTypedef;


//初始化
void USART1_Initialise(u32 bound);
void USART2_Initialise(u32 bound);
void USART3_Initialise(u32 bound);
void USART4_Initialise(u32 bound);
//串口接收函数配置
void USART_RxFuncConfig(void (* func)(uint8_t data,USART_TypeDef* USARTx));
//中断
void USART1_IRQHandler(void);
void USART2_IRQHandler(void);
void USART3_IRQHandler(void);
//发送
void USART_SendString(USART_TypeDef* USARTx,uint8_t * Send);
#endif

