#ifndef __TIMER_H__
#define __TIMER_H__

/***********************************************************************/
/*  FILE        :Timer.h                                               */
/*  DATE        :Mar, 2014                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8S003     Crystal: 4M HSI                          */
/*  DESCRIPTION :                                                      */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/
#include "type_def.h"

extern u16 LedREDTimer;
extern u16 LedYELLOWTimer;
extern u16 ErrStateTimeer;
extern uFLAG LedFlag;
extern u16 StateReadTimer;
//============================================ Timer 4
void TIM4_Init(void);
void TIM4_UPD_OVF(void);

#endif
