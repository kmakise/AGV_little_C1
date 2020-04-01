#ifndef __DELAY_H
#define __DELAY_H 			   

//添加头文件
#include "sys.h"  

//函数申明
void delay_init(void);
void delay_ms(u16 nms);
void delay_us(u32 nus);

#endif

