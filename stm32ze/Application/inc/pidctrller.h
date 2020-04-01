#ifndef __PIDCTRLLER_H
#define __PIDCTRLLER_H

#include "stm32f10x.h"

/* Structure type definition -------------------------------------------------*/
typedef struct
{
	float			de ;					//各个电机当前误差值 difference error
	float			fe ;					//各个电机误差积分
	float			de1;					//各个电机历史误差1
	float			de2;					//各个电机历史误差2
	int				out;					//各个通道最终PWM输出
	
}PIDDateBaseTypedef;			//pid数据结构类型

typedef struct
{
	float			kp;						//比例权重
	float			ki;						//积分权重
	float			kd;						//微分权重
	
}PIDParamBaseTypedef;			//pid参数结构类型




//设定目的速度
void SetTargetSpeed(int16_t s1,int16_t s2,int16_t s3,int16_t s4);

//pid控制器执行周期分频器
void PID_Divider(void);

#endif /*__PIDCTRLLER_H*/
