#ifndef __PIN_DEFINE_H__
#define __PIN_DEFINE_H__
/***********************************************************************/
/*  File Name   :Pin_Define.h                                          */
/*  DATE        :Mar, 2014                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8L151G6     Crystal: 16M HSI                       */
/*  DESCRIPTION :                                                      */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/
#include "Timer.h"

//以下是IO定义
/********************LED寄存器*****************************************/
#define LED_ON					1
#define LED_OFF					0
#define LED_YELLOW              PC_ODR_ODR0    //黄灯
#define LED_YELLOW_DDR          PC_DDR_DDR0    //黄灯方向
#define LED_YELLOW_CR1          PC_CR1_C10     //黄灯类型
#define LED_YELLOW_CR2          PC_CR2_C20     //黄灯输出频率

#define LED_RED                 PC_ODR_ODR1    //红灯
#define LED_RED_DDR             PC_DDR_DDR1    //方向
#define LED_RED_CR1             PC_CR1_C11     //类型
#define LED_RED_CR2             PC_CR2_C21     //输出频率


#define YELLOWLED_FLASH_SECOND()    {LED_YELLOW = LED_ON;LedYELLOWTimer = 750;}
#define YELLOWLED_OFF()     	    {LED_YELLOW = LED_OFF;LedYELLOWTimer = 0;}
#define YELLOWLED_FLASH()   	    {LED_YELLOW = !LED_YELLOW;LedYELLOWTimer = 60;}

#define REDLED_FLASH_SECOND()       {LED_RED = LED_ON;LedREDTimer = 750;}
#define REDLED_OFF()     	        {LED_RED = LED_OFF;LedREDTimer = 0;}
#define REDLED_FLASH()   	        {LED_RED = !LED_RED;LedREDTimer = 60;}

/********************LCD寄存器*****************************************/
#define	PIN_LCD_SCLK	        PD_ODR_ODR1		// 输出；LCD串行时钟(√)
#define	PIN_LCD_RST	       	 	PD_ODR_ODR2		// 输出；LCD复位脚  低电平有效(√)
#define	PIN_LCD_SDATA			PB_ODR_ODR1		// 输出；LCD串行数据(√)
#define	PIN_LCD_A0_RS			PD_ODR_ODR0		// 输出；LCD命令数据选择端  0--命令   1--数据(√)
#define	PIN_LCD_SEL				PD_ODR_ODR3		// 输出；芯片片选   低电平有效(√)
#define	PIN_LCD_LED				PA_ODR_ODR3

#define PIN_LCD_SCLK_DDR     	PD_DDR_DDR1  // Output
#define PIN_LCD_RST_DDR      	PD_DDR_DDR2  // Output
#define PIN_LCD_SDATA_DDR   	PB_DDR_DDR1  // Output
#define PIN_LCD_A0_RS_DDR    	PD_DDR_DDR0  // Output
#define PIN_LCD_SEL_DDR      	PD_DDR_DDR3  // Output
#define PIN_LCD_LED_DDR      	PA_DDR_DDR3  // Output

#define PIN_LCD_SCLK_CR1      	PD_CR1_C11  // Output
#define PIN_LCD_RST_CR1       	PD_CR1_C12  // Output
#define PIN_LCD_SDATA_CR1     	PB_CR1_C11  // Output
#define PIN_LCD_A0_RS_CR1     	PD_CR1_C10  // Output
#define PIN_LCD_SEL_CR1       	PD_CR1_C13  // Output
#define PIN_LCD_LED_CR1       	PA_CR1_C13  // Output

#define PIN_LCD_SCLK_CR2      	PD_CR2_C21  // Output
#define PIN_LCD_RST_CR2       	PD_CR2_C22  // Output
#define PIN_LCD_SDATA_CR2     	PB_CR2_C21  // Output
#define PIN_LCD_A0_RS_CR2    	PD_CR2_C20  // Output
#define PIN_LCD_SEL_CR2       	PD_CR2_C23  // Output
#define PIN_LCD_LED_CR2       	PA_CR2_C23  // Output

/******************以下是ADF7030-1寄存器************************************/
/* ADF7030-1 register interface */
#define ADF7030_REST			PC_ODR_ODR5
#define ADF7030_REST_DDR		PC_DDR_DDR5
#define ADF7030_REST_CR1		PC_CR1_C15
#define ADF7030_REST_CR2		PC_CR2_C25

#define ADF7030_GPIO3			PD_IDR_IDR4
#define ADF7030_GPIO3_DDR		PD_DDR_DDR4
#define ADF7030_GPIO3_CR1		PD_CR1_C14
#define ADF7030_GPIO3_CR2		PD_CR2_C24
//
#define ADF7030_GPIO4			PC_IDR_IDR4
#define ADF7030_GPIO4_DDR		PC_DDR_DDR4
#define ADF7030_GPIO4_CR1		PC_CR1_C14
#define ADF7030_GPIO4_CR2		PC_CR2_C24

#define ADF7030_GPIO5			PC_IDR_IDR6
#define ADF7030_GPIO5_DDR		PC_DDR_DDR6
#define ADF7030_GPIO5_CR1		PC_CR1_C16
#define ADF7030_GPIO5_CR2		PC_CR2_C26

#define ADF7030CLK      ADF7030_GPIO4
#define ADF7030DATA     ADF7030_GPIO5

/******************以下是KEY寄存器*******输入*****************************/
#define KEY_SW2					PA_IDR_IDR4
#define KEY_SW2_DDR				PA_DDR_DDR4
#define KEY_SW2_CR1				PA_CR1_C14
#define KEY_SW2_CR2				PA_CR2_C24

#define KEY_SW3					PA_IDR_IDR5
#define KEY_SW3_DDR				PA_DDR_DDR5
#define KEY_SW3_CR1				PA_CR1_C15
#define KEY_SW3_CR2				PA_CR2_C25

#define KEY_SW4					PA_IDR_IDR2
#define KEY_SW4_DDR				PA_DDR_DDR2
#define KEY_SW4_CR1				PA_CR1_C12
#define KEY_SW4_CR2				PA_CR2_C22

#define KEY_Empty       0
#define KEY_SW2_Down    1
#define KEY_SW3_Down    2
#define KEY_SW4_Down    3

/********************天线切换 CG2214M6控制引脚寄存器*****************************************/
#define CG2214M6_VC1          	PB_ODR_ODR2     //VC1
#define CG2214M6_VC1_DDR      	PB_DDR_DDR2     //方向
#define CG2214M6_VC1_CR1      	PB_CR1_C12     //模式MODE
#define CG2214M6_VC1_CR2      	PB_CR2_C22     //输出频率或者中断控制

#define CG2214M6_VC2          	PB_ODR_ODR3     //VC2
#define CG2214M6_VC2_DDR      	PB_DDR_DDR3     //方向
#define CG2214M6_VC2_CR1      	PB_CR1_C13     //模式MODE
#define CG2214M6_VC2_CR2      	PB_CR2_C23     //输出频率或者中断控制

#define CG2214M6_VC1_USE        {CG2214M6_VC1 = 1;CG2214M6_VC2 = 0;}
#define CG2214M6_VC2_USE        {CG2214M6_VC2 = 0;CG2214M6_VC2 = 1;}

#define CG2214M6_USE_T        CG2214M6_VC2_USE
#define CG2214M6_USE_R        CG2214M6_VC1_USE

/********************BEEP引脚寄存器*****************************************/
#define PIN_BEEP                PA_ODR_ODR0     // Output   蜂鸣器
#define PIN_BEEP_DDR         	PA_DDR_DDR0     // Output   蜂鸣器
#define PIN_BEEP_CR1            PA_CR1_C10     // Output   蜂鸣器//#define Receiver_OUT_STOP_CR1   PD_CR1_C11  // Output   受信机继电器stop  高电平有效

/********************WORK/TEST切换引脚寄存器*****************************************/
#define WORK_TEST           	PB_IDR_IDR0    // Input 受信机测试脚  高电平有效
#define WORK_TEST_DDR		    PB_DDR_DDR0    // Input 受信机测试脚  高电平有效
#define WORK_TEST_CR1       	PB_CR1_C10    // Input 受信机测试脚  高电平有效
#define WORK_TEST_CR2       	PB_CR2_C20    // Input 受信机测试脚  高电平有效


#endif

