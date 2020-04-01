#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "stm32f10x.h"

//系统主频
#define SYS_CLK   72000000

#define NULL 			0

//中断任务链表
typedef struct func{
	
	void (* function)(void);
	struct func *next;
	
} FuncLinkList;





//系统Systick初始化
void Systick_init(void);
//系统毫秒阻塞延时
void delay_ms(uint32_t ms);
//获得系统时间戳
uint32_t Sys_GetTick(void);
//创建中断执行任务
void creatIRQFunc(void (* func)(void));
//退出中断执行任务
void exitIRQFunc(void (* func)(void));

#endif /*__SYSTICK_H*/
