/******************** (C) COPYRIGHT  风驰iCreate嵌入式开发工作室 ********************/
#ifndef __SPI_H__
#define __SPI_H__
#include "iostm8l151g4.h"
#include "type_def.h"


#define SPI_CS          	PB_ODR_ODR4    //CS
#define SPI_CS_DDR      	PB_DDR_DDR4    //方向
#define SPI_CS_CR1       	PB_CR1_C14     //类型
#define SPI_CS_CR2     		PB_CR2_C24     //输出频率

#define SPI_CS_LOW()		(SPI_CS = 0)
#define SPI_CS_HIGH() 		(SPI_CS = 1)
#define SPI_CS_TOGGLE()  	(SPI_CS = ~SPI_CS)



void SPI_conf();
unsigned char SPI_SendByte(unsigned char byte);
void SPI_SendString(u16 Length,u8 *TX_Cache,u8 *RX_Cache);
void WAIT_SPI_IDEL(void);
u8 SPISendADF7030CFG(u8 *RF_CONFIG,u32 SIZE);

#endif

/******************* (C) COPYRIGHT 风驰iCreate嵌入式开发工作室 *****END OF FILE****/