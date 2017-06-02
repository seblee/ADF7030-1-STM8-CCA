/**
****************************************************************************
* @Warning :Without permission from the author,Not for commercial use
* @File    :spi.c
* @Author  :Xiaowine
* @date    :2017/4/13
* @version :V 1.0.0
*************************************************
* @brief   :
****************************************************************************
**/

#include "spi.h"
#include "ADF7030_1.h"

/**************************************************************************
 * 函数名：SPI_conf
 * 描述  ：SPI模块配置函数
 * 输入  ：无
 *
 * 输出  ：无
 * 返回  ：无
 * 调用  ：外部调用
 *************************************************************************/
void SPI_conf()
{
    PB_DDR |= 1 << 5; //SCK
    PB_CR1 |= 1 << 5; //output

    PB_DDR |= 1 << 6; //MOSI
    PB_CR1 |= 1 << 6; //output

    PB_DDR &= ~(1 << 7); //MISO
    PB_CR1 |= 1 << 7;    //in put with pull-up

    CLK_PCKENR1 |= 0x10;
    SPI1_CR1_SPE = 0;      //禁止SPI1
    SPI1_CR1_LSBFIRST = 0; //先发送MSB
    SPI1_CR1_BR = 0;       //fSYSCLK/2 = 8MHz   Baud = fSYSCLK/(2^(SPI1_CR1_BR+1)) eg.	//000: fSYSCLK/2  001: fSYSCLK/4
    SPI1_CR1_MSTR = 1;     //Master configuration 设置为主模式
    SPI1_CR1_CPOL = 0;     //0: SCK to 1 when idle		空闲状态时SCK为低电平									(MISO和MOSI在CLK的上升沿载入，下降沿取样)
    SPI1_CR1_CPHA = 0;     //0: The first clock transition is the second data capture edge (MISO和MOSI在CLK的上升沿载入，下降沿取样)

    SPI1_CR2_BDM = 0;    //2-line unidirectional data mode selected
                         //	SPI1_CR2_BDOE			= 0;
    SPI1_CR2_CRCEN = 0;  //0: CRC calculation disabled
    SPI1_CR2_RXONLY = 0; //0: Full duplex (Transmit and receive)
    SPI1_CR2_SSM = 1;    //0: Software slave management disabled
    SPI1_CR2_SSI = 1;    //1: Master mode

    //    SPI1_ICR     = 0x00;
    SPI1_ICR_TXIE = 0;    //TXE interrupt masked
    SPI1_ICR_RXIE = 0;    //RXNE interrupt masked
    SPI1_ICR_ERRIE = 0;   //Error interrupt is masked
    SPI1_ICR_WKIE = 0;    //Wakeup interrupt masked
    SPI1_ICR_TXDMAEN = 0; //Tx buffer DMA disabled
    SPI1_ICR_RXDMAEN = 0; //Rx buffer DMA disabled

    SPI1_CR1_SPE = 1; //使能SPI1

    //    CLK_PCKENR1 |= 0x10;
    //    SPI1_CR1 = 0x04;
    //    SPI1_CR2 = 0x03;
    //    SPI1_CRCPR = 0x07;
    //    SPI1_CR1 |= 0x40;

    SPI_CS_DDR = Output; /* 设置数据方向寄存器 1为输出，0为输入--查看STM8寄存器.pdf P87 */
    SPI_CS_CR1 = 1;      /* 设置推挽输出--查看STM8寄存器RM0031.pdf 10.9*/
    SPI_CS_CR2 = 1;      /* 设置输出频率 1为10M，0为2M--查看STM8寄存器.pdf P89 */
}

/**************************************************************************
 * 函数名：SPI_SendByte
 * 描述  ：SPI模块发送函数
 * 输入  ：无
 *
 * 输出  ：无
 * 返回  ：无
 * 调用  ：外部调用
 *************************************************************************/
unsigned char SPI_SendByte(unsigned char byte)
{
    u8 dat;
    dat = SPI1_DR;
    while (!(SPI1_SR & 0x02))
        ;           /* 等待发送寄存器为空 */
    SPI1_DR = byte; /* 将发送的数据写到数据寄存器 */
    __asm("nop");
    while (!(SPI1_SR & 0x01))
        ; /* 等待接受寄存器满 */
    dat = SPI1_DR;
    return dat;
}
/**
****************************************************************************
* @Function	: void WAIT_SPI_IDEL(void)
* @file		: spi.c
* @Author	: Xiaowine
* @date		: 2017/4/11
* @version	: V1.0
* @brief	: 等待SPI空闲
**/
void WAIT_SPI_IDEL(void)
{
    while (SPI1_SR & 0x80)
        ;
}

/**
****************************************************************************
* @Function	: void SPI_SendString(u16 Length,u8 *TX_Cache,u8 *RX_Cache)
* @file		: spi.c
* @Author	: Xiaowine
* @date		: 2017/4/11
* @version	: V1.0
* @brief	:
**/
void SPI_SendString(u16 Length, u8 *TX_Cache, u8 *RX_Cache)
{
    u16 Tp_i;
    SPI_CS_LOW();
    RX_COUNT = 0;
    for (Tp_i = 0; Tp_i < Length; Tp_i++)
    {
        ADF7030_Read_OneByte = SPI_SendByte(*(TX_Cache + Tp_i));
        ADF7030_RESIGER_VALUE_READ = ADF7030_RESIGER_VALUE_READ << 8;
        ADF7030_RESIGER_VALUE_READ = ADF7030_RESIGER_VALUE_READ | ADF7030_Read_OneByte;
        *(RX_Cache + (RX_COUNT % SPI_REV_BUFF_LONG)) = ADF7030_Read_OneByte;
        RX_COUNT++;
    }
    SPI_CS_HIGH();
}
/**
****************************************************************************
* @Function : u8 SPISendADF7030CFG(u8 *RF_CONFIG,u16 SIZE)
* @File     : spi.c
* @Program  : *RF_CONFIG:cfg数据;length: 数据长度
* @Created  : 2017/4/21 by Xiaowine
* @Brief    :
* @Version  : V1.0
**/
u8 SPISendADF7030CFG(u8 *RF_CONFIG, u32 SIZE)
{
    u32 array_position = 0;
    u32 length;
    u8 *pSeqData;
    do
    {
        // Calculate the number of bytes to write
        length = ((u32) * (RF_CONFIG + array_position) << 16) |
                 ((u32) * (RF_CONFIG + array_position + 1) << 8) |
                 ((u32) * (RF_CONFIG + array_position + 2));
        if (length > 0xffff)
            return FAILURE;
        pSeqData = (RF_CONFIG + array_position + 3);

        WaitForADF7030_FIXED_DATA(); //等待芯片空闲/可接受CMD状态
        DELAY_30U();
        SPI_SendString(length - 3, pSeqData, SPI_RECEIVE_BUFF);
        array_position += length;
    } while (array_position < SIZE);
    return SUCESS;
}
