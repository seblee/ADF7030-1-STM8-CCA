/***********************************************************************/
/*  FILE        :macro.h                                               */
/*  DATE        :Mar, 2012                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8S207R8     Crystal: 3.6864M                       */
/*  DESCRIPTION :Main routine for UHF Receive 400M                     */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/
#ifndef MACRO_H
#define MACRO_H
	//============================================
	#define	uchar		unsigned char
	#define	uint		unsigned int
	#define	ulong		unsigned long
	//--------------------------------------------

	#define	_NOP()	asm("nop")					// 汇编指令:【nop】
	#define	_EI()	asm("sim")					// 汇编指令:关全局中断
	#define	_DI()	asm("rim")					// 汇编指令:开全局中断
	//============================================
#endif


