#ifndef __INITIAL_H__
#define __INITIAL_H__
#include "type_def.h"
/***********************************************************************/
/*  FILE        :initial.h                                             */
/*  DATE        :Mar, 2014                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8L151G6     Crystal: 16M HSI                       */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/
/***********************系统预定义**********************/
#define	UINT8	    unsigned char
#define	INT8	    char
#define	UINT16	    unsigned int
#define	INT16	    int
#define	UINT32	    unsigned long
#define	INT32	    long

#define uchar       unsigned char
#define uint        unsigned int
#define ulong       unsigned long

#define _NOP()      asm( " nop " )
#define _EI()       asm( " rim " )
#define _DI()       asm( " sim " )




// 方向控制寄存器1（1=输出／0=输入）
#define Input				0
#define Output				1
/*******************系统预定义  end**********************/


      typedef union
      {
        UINT32  whole_reg;
        UINT8   byte[4];    // Warning: Be endian-specific when accessing bytes

      } ADF70XX_REG_T;

        typedef union {	  // ID No.
        UINT32	IDL ;
        UINT8	IDB[4];
      }uni_rom_id;


extern u16 X_COUNT;
extern u16 X_ERR;//记录错误的个数

extern uFLAG YellowLedFlag,RedLedFalg;
#define YellowStutue    YellowLedFlag.BYTE
#define RedStutue       RedLedFalg.BYTE
#define LEDOFFFLAG          0
#define LEDONFLAG           1
#define LEDFLASHASECONDFLAG 2
#define LEDFLASHFLAG        3

void LED_GPIO_Init(void);//初始化LED
void LCD_GPIO_Init(void);//初始化LCD IO
void KEY_GPIO_Init(void);//KEY IO
void CG2214M6_GPIO_Init(void);//CG2214M6 IO
void ADF7030_GPIO_INIT(void);//ADF7030 IO(REST & GPIO3)
u8 KEY_SCAN(u8 mode);//按键扫描
void RAM_clean(void);						// 清除RAM
void VHF_GPIO_INIT(void);					// CPU端口设置
void SysClock_Init( void ); 				// 系统时钟（外部时钟）
void beep_init( void );
void Delayus(unsigned char timer);
void WDT_init(void);
void ClearWDT(void);
void RF_BRE_Check(void);
void LEDCtr(void);



#endif

