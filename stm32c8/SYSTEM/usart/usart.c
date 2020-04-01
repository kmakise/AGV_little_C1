#include "sys.h"
#include "usart.h"	
#include <stdarg.h>


//加入以下代码,支持printf函数,而不需要选择use MicroLIB	  
#if 1
#pragma import(__use_no_semihosting)             
//标准库需要的支持函数                 
struct __FILE 
{ 
	int handle; 

}; 

FILE __stdout;       
//定义_sys_exit()以避免使用半主机模式    
_sys_exit(int x) 
{ 
	x = x; 
} 
//重定义fputc函数 
int fputc(int ch, FILE *f)
{      
	while((USART1->SR&0X40)==0);//循环发送,直到发送完毕   
    USART1->DR = (u8) ch;      
	return ch;
}
#endif 

/*使用microLib的方法*/
 
//int fputc(int ch, FILE *f)
//{
//	USART_SendData(USART1, (uint8_t) ch);

//	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET) {}	
//   
//    return ch;
//}
//int GetKey (void)  { 

//    while (!(USART1->SR & USART_FLAG_RXNE));

//    return ((int)(USART1->DR & 0x1FF));
//}

// 
//#if EN_USART1_RX   //如果使能了接收
//串口1中断服务程序
//注意,读取USARTx->SR能避免莫名其妙的错误   	
u8 USART_RX_BUF[USART_REC_LEN];     //接收缓冲,最大USART_REC_LEN个字节.
//接收状态
//bit15，	接收完成标志
//bit14，	接收到0x0d
//bit13~0，	接收到的有效字节数目
u16 USART_RX_STA=0;       //接收状态标记	  
  
void uart_init(u32 bound){
  //GPIO端口设置
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);	//使能USART1，GPIOA时钟
  
	//USART1_TX   GPIOA.9
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.9
   
  //USART1_RX	  GPIOA.10初始化
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.10  

  //Usart1 NVIC 配置
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1 ;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
  
   //USART 初始化设置

	USART_InitStructure.USART_BaudRate = bound;//串口波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式

  USART_Init(USART1, &USART_InitStructure); //初始化串口1
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//开启串口接受中断
  USART_Cmd(USART1, ENABLE);                    //使能串口1 

}

u8 USART2_RX_BUF[255]; //串口2接收数据缓存区
u16 USART2_RX_STA=0;  //串口2接收标志
void USART1_IRQHandler(void)                	//串口1中断服务程序
{
	u8 Res;

	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
		{
			Res =USART_ReceiveData(USART1);	//读取接收到的数据		
			if((USART2_RX_STA & 0x8000) == 0) //未接收完成
		{
			if(USART2_RX_STA & 0x4000)//接收到0x0d
			{
				if(Res!=0x0a)USART2_RX_STA=0;
				else USART2_RX_STA|=0x8000;	
			}
			else
			{
				if (Res == 0x0d)
				{
					USART2_RX_STA |= 0x4000;					
				}
				else
				{
					USART2_RX_BUF[(USART2_RX_STA & 0x3fff)] = Res;
					USART2_RX_STA++;
					if(USART2_RX_STA>50)USART2_RX_STA=0;
				}
			}
			
		}
			
    } 

} 


//void UartOneSendChar(char tt)
//{
//	USART_ClearFlag(USART1,USART_FLAG_TC); 
//	USART1->DR=tt;
//	while((USART1->SR&0X40)==0)			//等待发送结束
//		;
//}


////串口2配置函数
//void usart_config(u32 bound)
//{
//	GPIO_InitTypeDef GPIO_InitStructure;
//	
//	USART_InitTypeDef USART_InitStructure;
//	
//	NVIC_InitTypeDef NVIC_InitStructure;
//	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
////	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
//	
////	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
//	GPIO_Init(GPIOA, &GPIO_InitStructure);
//	
////	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
//	GPIO_Init(GPIOA, &GPIO_InitStructure);
//	
//	USART_InitStructure.USART_BaudRate = bound;//传感器规定传输波特率为：2400
//	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
//	USART_InitStructure.USART_StopBits = USART_StopBits_1;
//	USART_InitStructure.USART_Parity = USART_Parity_No;
//	USART_InitStructure.USART_HardwareFlowControl =USART_HardwareFlowControl_None;
//	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;		
//	USART_Init(USART2, &USART_InitStructure);
//	
////	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//串口1已经设置过优先级分组
//	
//	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;//抢占优先级
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;//从优先级
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	
//	NVIC_Init(&NVIC_InitStructure);

//	USART_Cmd(USART2, ENABLE);//使能串口2
//	
//	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//使能串口2中断
//	
//}

//void usart2_Printf (char *fmt, ...) 
//{ 
//char buffer[200];  // CMD_BUFFER_LEN??????? 
//u8 i = 0; 

//va_list arg_ptr; 
//va_start(arg_ptr, fmt);   
//vsnprintf(buffer, 200, fmt, arg_ptr); 
//while ((i < 199) && buffer[i]) 
//{ 
//        USART_SendData(USART2, (u8) buffer[i++]); 
//while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);  
//} 
//va_end(arg_ptr); 
//} 
////串口2发送函数，此工程中并未用串口2发送数据
//void sendFun(u8 *str)
//{
//	u16 i = 0;
//	while(str[i] != '\0')
//	{
//		USART_SendData(USART2, str[i]);
//		while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) != SET)
//			;
//		i++;
//		USART_ClearFlag(USART2,USART_FLAG_TXE);
//	}
//}

//void UartTwoSendChar(char tt)
//{
//	USART_ClearFlag(USART2,USART_FLAG_TC); 
//	USART2->DR=tt;
//	while((USART2->SR&0X40)==0)			//等待发送结束
//		;
//}



////void USART2_IRQHandler()
////{	
////	u8 Res2 = 0;
////	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET) 
////	{
////		Res2 = USART_ReceiveData(USART2); //(USART1->DR); 
//////			usart2_Printf("%x\n",Res2);	
////		if((USART2_RX_STA & 0x8000) == 0) //未接收完成
////		{
////			if(USART2_RX_STA & 0x4000)//接收到0x0d
////			{
////				if(Res2!=0x0a)USART2_RX_STA=0;
////				else USART2_RX_STA|=0x8000;	
////			}
////			else
////			{
////				if (Res2 == 0x0d)
////				{
////					USART2_RX_STA |= 0x4000;					
////				}
////				else
////				{
////					USART2_RX_BUF[(USART2_RX_STA & 0x3fff)] = Res2;
////					USART2_RX_STA++;
////					if(USART2_RX_STA>50)USART2_RX_STA=0;
////				}
////			}
////			
////		}   		 
////   } 
////}

//void uart3_init(u32 bound)
//{
//  //GPIO端口设置
//  GPIO_InitTypeDef GPIO_InitStructure;
//	USART_InitTypeDef USART_InitStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
//	 
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
//  
//	//USART1_TX   GPIOA.9
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //PA.9
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
//  GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOA.9
//   
//  //USART1_RX	  GPIOA.10初始化
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;//PA10
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
//  GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOA.10  

//  //Usart1 NVIC 配置
//  NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//抢占优先级3
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		//子优先级3
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
//	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
//  
//   //USART 初始化设置

//	USART_InitStructure.USART_BaudRate = bound;//串口波特率
//	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
//	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
//	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
//	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
//	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式

//  USART_Init(USART3, &USART_InitStructure); //初始化串口1
//  USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);//开启串口接受中断
//  USART_Cmd(USART3, ENABLE);                    //使能串口1 

//}

//extern u8 cntRxd;
//extern u8 bufRxd[100]; //???????
//void USART3_IRQHandler(void)                	//串口1中断服务程序
//{
//	u8 Res;

//	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
//		{
//			Res =USART_ReceiveData(USART3);	//读取接收到的数据		
//			if (cntRxd < sizeof(bufRxd))
//      {
//         bufRxd[cntRxd++] = Res; 
////				sendFun(&Res);
////				sendFun(&bufRxd[cntRxd-1]);
////				sendFun(&cntRxd);
//				
//      }		
//			
//    } 

//} 


//void UartThreeSendChar(char tt)
//{
//	USART_ClearFlag(USART3,USART_FLAG_TC); 
//	USART3->DR=tt;
//	while((USART3->SR&0X40)==0)			//等待发送结束
//		;
//}
