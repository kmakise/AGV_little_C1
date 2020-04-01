#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 
typedef struct
{
	uint8_t Buf[100];	//串口接收缓冲区
	uint8_t Over;			//串口接受检查
	uint8_t Len;				//串口接受长度
}UartBufTypedef;


//初始化
void USART1_Initialise(u32 bound);
void USART2_Initialise(u32 bound);
void USART3_Initialise(u32 bound);
//串口接收配置
void USART_RxFuncConfig(USART_TypeDef* USARTx , void (* func)(uint8_t data));
//中断
void USART1_IRQHandler(void);
void USART2_IRQHandler(void);
void USART3_IRQHandler(void);
//发送
void USART_SendString(USART_TypeDef* USARTx,uint8_t * Send);
#endif

