/**
  ******************************************************************************
  * @file    syn7318.c
  * @author  张东
  * @version V1.0.0
  * @date    2019-11-7
  * @brief   语音播报与提示音
  ******************************************************************************
  */
#include "syn7318.h"
#include "usart.h"
#include "string.h"
#include "systick.h"



//串口4中断接收
void UART4_IRQHandler(void)
{
	
}	


//串口4发送一个字符
int U4SendChar(int ch) 
{
	 while(USART_GetFlagStatus(UART4,USART_FLAG_TC)!=SET);  //等待发送结束
   USART_SendData(UART4,ch); 
}
/*********************************************************************
【函 数 名】：SYN7318_Put_Char----发送一个字节函数
【参数说明】：txd---待发送的字节（8位）
【简    例】：SYN7318_Put_Char('d');  发送‘d’
*********************************************************************/
void SYN7318_Put_Char(uint8_t txd)
{
	U4SendChar(txd);
}
/*********************************************************************
【函 数 名】：SYN7318_Put_String----发送字符串函数
【参数说明】：Pst：存放字符串的数组名
              Length：字符串长度
【简    例】：uchar d[4] = {0x00,0x01,0x02,0x03};
              SYN7318_Put_String(d,4); ---发送数组d中的元素
*********************************************************************/
void SYN7318_Put_String(uint8_t* Pst,uint8_t Length)
{ 
  uint8_t i;
	for(i = 0; i < Length; i++)
	{
		SYN7318_Put_Char(Pst[i]);
	}
}
/*********************************************************************
【函 数 名】：SYN_TTS----语音合成播放函数
【参数说明】：Pst：存放要合成播放的文本的数组名
【简    例】：uchar Data[] = {"北京龙邱"};
              SYN_TTS(Data); -----合成播放北京龙邱
*********************************************************************/
void SYN_TTS(uint8_t *Pst)
{
	uint8_t Length;
	uint8_t Frame[5];   //保存发送命令的数组
	uint32_t max_tim = 0;
	
	Length = strlen((char *)Pst);
	Frame[0] = 0xFD;      //帧头
	Frame[1] = 0x00;
	Frame[2] = Length+2;
	Frame[3] = 0x01;      //语音合成播放命令
	Frame[4] = 0x00;      //播放编码格式为“GB2312”
	
	SYN7318_Put_String(Frame, 5);	
	SYN7318_Put_String(Pst, Length);
	
//	SYN7318_Get_String(Back,4);
//    max_tim = gt_get() + 2000;
//	//接收成功
//	while(!(Back[3] == 0x41) && gt_get_sub(max_tim))
//	{
//		SYN7318_Get_String(Back,4);
//	}
//	
//	max_tim = gt_get() + 2000;	
//	//空闲监测
//	SYN7318_Get_String(Back,4);
//	while(!(Back[3] == 0x4f) && gt_get_sub(max_tim))
//	{
//		SYN7318_Get_String(Back,4);
//	}
}


//音频文件播放
void SoundFilePlayer(const char * fn)
{
	//指令
	uint8_t cmd[100];
	//文件描述长度
	uint16_t fn_len = strlen((const char *)fn);
	
	//帧头
	cmd[0] = 0xfd;
	
	//消息长度
	cmd[1] = ((fn_len + 2) & 0xff00) >> 8;
	cmd[2] = ((fn_len + 2) & 0x00ff);
	
	//命令字
	cmd[3] = 0x61;
	
	//命令参数
	cmd[4] = 0x01;
	
	//输入数据段
	for(int i = 0;i < fn_len;i++)
	{
		cmd[5 + i] = fn[i];
	}
	//发送数据
	SYN7318_Put_String(cmd,fn_len + 5);
}



/*测试*/
void syntest(void)
{
	delay_ms(4000);
	SoundFilePlayer("E:\\mailkida\\06 msg15.mp3");
	
}


void SoundLoop(void)
{
	
}





