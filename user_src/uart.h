#ifndef __UART_H__
#define __UART_H__
/***********************************************************************/
/*  FILE        :Uart.H                                                */
/*  DATE        :Mar, 2014                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8L151G6     Crystal: 16M HSI                       */
/*  DESCRIPTION :                                                      */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/

void UART1_INIT(void);
void UART1_RX_RXNE(void);
void Send_char(unsigned char ch);
void UART1_end(void);
void PC_PRG(void);

#endif
