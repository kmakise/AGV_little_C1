/**
  ******************************************************************************
  * @file    systick.c
  * @author  张东
  * @version V1.0.0
  * @date    2019-11-7
  * @brief   systick定时器的主中断与系统运行时间戳的提供
  ******************************************************************************
  */
/*include file ---------------------------------------------------------------*/
#include "stm32f10x.h"
#include "systick.h"
#include "stdlib.h"
/*Golbal data space ----------------------------------------------------------*/
//系统时间戳
uint32_t g_SysTick = 0;
//系统中断任务列表
FuncLinkList g_IRQFuncList = {.function = NULL , .next = NULL};

//系统Systick初始化
void Systick_init(void)
{
	if (SysTick_Config(SYS_CLK/1000))     //1ms
	{        
			while (1);
	}
	NVIC_SetPriority(SysTick_IRQn, 0x0);
}

//获得系统时间戳
uint32_t Sys_GetTick(void)
{
	return g_SysTick;
}

//系统毫秒阻塞延时
void delay_ms(uint32_t ms)
{
	uint32_t lasttick = Sys_GetTick();
	while((Sys_GetTick() - lasttick) < ms);
}


//创建中断执行任务
void creatIRQFunc(void (* func)(void))
{
	if(g_IRQFuncList.function == NULL)
	{
		g_IRQFuncList.function = func;
	}
	else
	{
		//指向当前节点
		FuncLinkList * node = &g_IRQFuncList;
		//找到下一个为空的节点
		while(node->next != NULL)
		{
			node = node->next;
		}
		//为任务描述节点分配空间
		FuncLinkList  * newNode = (FuncLinkList *)malloc(sizeof(FuncLinkList));
		
		//创建任务
		newNode->function = func;
		newNode->next = NULL;
		node->next = newNode;
	}
}

//退出中断执行任务
void exitIRQFunc(void (* func)(void))
{
	//第一个任务是要删除的任务
	if(g_IRQFuncList.function == func)
	{
		//第一个任务的next为空
		if(g_IRQFuncList.next == NULL)
		{
			g_IRQFuncList.function = NULL;
		}
		else
		{
			g_IRQFuncList.function = g_IRQFuncList.next->function;
			//指向当前即将释放节点的下一个节点
			FuncLinkList * Nextnode = g_IRQFuncList.next->next;
			//释放下一个
			free(g_IRQFuncList.next);
			//写入下一个
			g_IRQFuncList.next = Nextnode;
		}
	}
	//第一个任务不是要办事处的任务
	else
	{
		//指向当前节点
		FuncLinkList * node = &g_IRQFuncList;
		
		//搜索要退出的任务
		while(node->next->function != func)//当前节点是要删除的节点
		{
			node = node->next;
			
			//无法找到指定的方法
			if(node->next == NULL)
			{
				return;
			}
		}
		//指向当前即将释放节点的下一个节点
		FuncLinkList * Nextnode = node->next->next ;
		
		//释放节点内存
		free(node->next);
		//指针清空
		node->next = Nextnode;
	}
}

//中断任务执行器
void runIRQFunc(void)
{
	//指向当前节点
	FuncLinkList * node = &g_IRQFuncList;
	
	//执行到结束
	while(node->function != NULL)
	{
		//执行
		node->function();
		
		//结束
		if(node->next == NULL)
		{
			return;
		}
		//移动
		node = node->next;
	}
}


//systick 中断
void SysTick_Handler()
{
	//中断执行任务
	runIRQFunc();
	//系统时间戳
	g_SysTick++;
}


	
	