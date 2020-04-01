#ifndef __ENCODER_H
#define __ENCODER_H

#include "stm32f10x.h"

void TIM1_EncoderMode(u32 prescaler,u32 period);
void TIM2_EncoderMode(u32 prescaler,u32 period);
void TIM3_EncoderMode(u32 prescaler,u32 period);
void TIM4_EncoderMode(u32 prescaler,u32 period);



#endif /*__ENCODER_H*/
