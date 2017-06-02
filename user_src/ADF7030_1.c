
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>        /* For true/false definition                      */
#include <stdio.h>
#include "spi.h"
#include "Pin_define.h"		// Ð¾Æ¬Òý½Å¶¨ÓÚ
#include "ram.h"
#include "ADF7030_1.h"
#include "ID_Decode.h"
#include "lcd.h"
#include "type_def.h"
u8 FilterChar[2][1] = {
    {' '},
    {'G'}
};

u8   SPI_SEND_BUFF[SPI_SEND_BUFF_LONG] = {0X55};
u8   SPI_RECEIVE_BUFF[SPI_REV_BUFF_LONG] = {0};
u32   SPI_Receive_DataForC[6];        //C²¿
u16  Head_0x5515_or_0x5456 = 0;
u32  ADF7030_RESIGER_VALUE_READ = 0;
u8   ADF7030_Read_OneByte = 0;
u8   RX_COUNT = 0;
u8   Radio_State = 0;
u32  CCA_READBACK_Cache = 0;
UINT32 DATA_Packet_ID=0;
UINT8  DATA_Packet_Control=0;
UINT8  DATA_Packet_Contro_buf=0;   //2015.3.24ÐÞÕý

u8 BREState = 0;

void DELAY_30U(void)
{
    u8 Tp_i=0;
    for(Tp_i=0;Tp_i<17;Tp_i++);//???????30U
}

void DELAY_XX(void)
{
    u32 cyw_delay=0;
    for(cyw_delay=0;cyw_delay<0x20000;cyw_delay++);
}

/**
****************************************************************************
* @Function : void ADF7030Init(void)
* @File     : ADF7030_1.c
* @Program  : none
* @Created  : 2017/4/12 by Xiaowine
* @Brief    : ³õÊ¼»¯ADF7030§àÐ¾Æ¬
* @Version  : V1.0
**/
void ADF7030Init(void)
{
    SPI_conf(); //³õÊ¼»¯spi
    ADF7030_REST = 0;   //ADF7030Ð¾Æ¬³õÊ¼»¯
    Delayus(50);
    ClearWDT();
    ADF7030_REST = 1;   //ADF7030Ð¾Æ¬³õÊ¼»¯Íê³É
    CG2214M6_USE_R;
    ADF7030_CHANGE_STATE(STATE_PHY_ON);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    ADF7030_CHANGE_STATE(STATE_PHY_OFF);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬

    ClearWDT(); // Service the WDT
    ADF7030_WRITING_PROFILE_FROM_POWERON();
    ClearWDT(); // Service the WDT
    if(WORK_TEST == 1)ADF7030_RECEIVING_FROM_POWEROFF();
//    else ADF7030_CCA_FROM_POWEROFF();
    ClearWDT(); // Service the WDT
    YELLOWLED_OFF();
}              // 0x7E,0xa8,0x69,0xc8

void ADF7030_CHANGE_STATE(u8 x_state)
{
	SPI_SEND_BUFF[0]=x_state;
	WAIT_SPI_IDEL();
	SPI_SendString(1,SPI_SEND_BUFF,SPI_RECEIVE_BUFF);
	WAIT_SPI_IDEL();
}
/**
****************************************************************************
* @Function : u8 RadioChangeState(ADF7030_RADIO_STATE CMD)
* @File     : ADF7030_1.c
* @Program  :
* @Created  : 2017/4/25 by Xiaowine
* @Brief    :
* @Version  : V1.0
**/
u8 RadioChangeState(u8 STATE_CMD)
{
    u8 state;
    ADF7030_1_STATUS_TYPE STATUSCache;
    STATUSCache.VALUE = 0;
    ADF7030_CHANGE_STATE(STATE_CMD);
    while((STATUSCache.CMD_READY == 0)&&(STATUSCache.FW_STATUS == TRANSITION_STATUS_TRANSITION))
    {
        STATUSCache = GET_STATUE_BYTE();
    }
    ADF7030_READ_REGISTER_NOPOINTER_LONGADDR(ADDR_MISC_FW,6);//??7030????
    state = (ADF7030_RESIGER_VALUE_READ >> 8) & 0x00003F;
    ClearWDT(); // Service the WDT
    if(state == (STATE_CMD & 0x0f))
        return SUCESS;
    else return FAILURE;
}
/**
 ****************************************************************************
 * @Function : u8 ADF7030_GET_FW_STATE(void)
 * @File     : ADF7030_1.c
 * @Program  :
 * @Created  : 2017/5/9 by Xiaowine
 * @Brief    :
 * @Version  : V1.0
**/
u8 ADF7030_GET_FW_STATE(void)
{
    u8 state;
    while(GET_STATUE_BYTE().CMD_READY == 0);
    DELAY_30U();
    ADF7030_READ_REGISTER_NOPOINTER_LONGADDR(ADDR_MISC_FW,6);//??7030????
    state = (ADF7030_RESIGER_VALUE_READ >> 8) & 0x00003F;
    return state;
}

void ADF7030_FIXED_DATA(void)
{
    SPI_SEND_BUFF[0]=0xff;
    SPI_SEND_BUFF[1]=0xff;
    WAIT_SPI_IDEL();
	SPI_SendString(2,SPI_SEND_BUFF,SPI_RECEIVE_BUFF);
    WAIT_SPI_IDEL();
}
//???ADF7030????
//x_fnum ??0xff???
u32 ADF7030_READ_REGISTER_NOPOINTER_LONGADDR(u32 x_ADDR,u8 x_fnum)
{
    u8  Tp_sub=0;
    u8 Tp_i=0;
    SPI_SEND_BUFF[Tp_sub++] = 0X78;
    SPI_SEND_BUFF[Tp_sub++] = (x_ADDR>>24)&0XFF;
    SPI_SEND_BUFF[Tp_sub++] = (x_ADDR>>16)&0XFF;
    SPI_SEND_BUFF[Tp_sub++] = (x_ADDR>>8)&0XFF;
    SPI_SEND_BUFF[Tp_sub++] = (x_ADDR)&0XFF;

    for(Tp_i=0;Tp_i<x_fnum;Tp_i++)
    {
        SPI_SEND_BUFF[Tp_sub++] = 0xff;
    }

    WAIT_SPI_IDEL();
    SPI_SendString(Tp_sub,SPI_SEND_BUFF,SPI_RECEIVE_BUFF);
    WAIT_SPI_IDEL();
    return ADF7030_RESIGER_VALUE_READ;

}

//????
//?? x_ADDR ??   x_data ???  x_long????
void ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(u32 x_ADDR,const u8 *x_data,u16 x_long)
{
	u16 Tp_long;
	SPI_SEND_BUFF[0] = 0X38;
	SPI_SEND_BUFF[1] = (x_ADDR>>24)&0XFF;
	SPI_SEND_BUFF[2] = (x_ADDR>>16)&0XFF;
	SPI_SEND_BUFF[3] = (x_ADDR>>8)&0XFF;
	SPI_SEND_BUFF[4] = (x_ADDR)&0XFF;
	for(Tp_long=0;Tp_long<x_long;Tp_long = Tp_long+4)//??????????
	{
        SPI_SEND_BUFF[5+Tp_long] = x_data[Tp_long+3];
        SPI_SEND_BUFF[5+Tp_long+1] = x_data[Tp_long+2];
        SPI_SEND_BUFF[5+Tp_long+2] = x_data[Tp_long+1];
        SPI_SEND_BUFF[5+Tp_long+3] = x_data[Tp_long];
	}
	WAIT_SPI_IDEL();

	SPI_SendString(x_long+5,SPI_SEND_BUFF,SPI_RECEIVE_BUFF);
	WAIT_SPI_IDEL();
}
/**
 ****************************************************************************
 * @Function : void ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR_MSB(u32 xx_ADDR,u32 x_data)
 * @File     : ADF7030_1.c
 * @Program  :
 * @Created  : 2017/5/2 by Xiaowine
 * @Brief    :
 * @Version  : V1.0
**/
void ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR_MSB(u32 x_ADDR,u32 x_data)
{
	SPI_SEND_BUFF[0] = 0X38;
	SPI_SEND_BUFF[1] = (x_ADDR>>24)&0XFF;
	SPI_SEND_BUFF[2] = (x_ADDR>>16)&0XFF;
	SPI_SEND_BUFF[3] = (x_ADDR>>8)&0XFF;
	SPI_SEND_BUFF[4] = (x_ADDR)&0XFF;
    SPI_SEND_BUFF[5] = (x_data >> 24) & 0XFF;
    SPI_SEND_BUFF[6] = (x_data >> 16) & 0XFF;
    SPI_SEND_BUFF[7] = (x_data >> 8) & 0XFF;
    SPI_SEND_BUFF[8] = x_data & 0XFF;
	WAIT_SPI_IDEL();

	SPI_SendString(9,SPI_SEND_BUFF,SPI_RECEIVE_BUFF);
	WAIT_SPI_IDEL();
}

//
u32 ADF7030_GET_MISC_FW(void)//??MISC_FW?????
{

    DELAY_30U();
    ADF7030_FIXED_DATA();
    DELAY_30U();
    ADF7030_CHANGE_STATE(STATE_PHY_ON);
    DELAY_30U();
    ADF7030_FIXED_DATA();
    DELAY_30U();
    ADF7030_READ_REGISTER_NOPOINTER_LONGADDR(ADDR_MISC_FW,6);//??7030????
    return 0;
}

void ADF7030_WRITING_PROFILE_FROM_POWERON(void)
{
    ADF7030_REST = 0;   //ADF7030Ð¾Æ¬³õÊ¼»¯
    Delayus(50);
    ClearWDT();
    ADF7030_REST = 1;   //ADF7030Ð¾Æ¬³õÊ¼»¯Íê³É

    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_CHANGE_STATE(STATE_PHY_OFF);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_PROFILE_START,CONST_DATA_PROFILE_200002E4,PROFILE_LONG);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_GENERIC_START,CONST_GENRIC_PACKET_200004F4,GENRIC_LONG);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_ANAFILT_LUTS_0TO5,CONST_ANAFILT_LUTS_2000060C,ANAFILTLUTS_LONG);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_ANAFILT_LUTS_6TO11,CONST_ANAFILT_LUTS_20000624,ANAFILTLUTS_LONG);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_ANAFILT_LUTS_12TO17,CONST_ANAFILT_LUTS_2000063C,ANAFILTLUTS_LONG);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_DIGFILT_LUTS_0TO7,CONST_DIGFILT_LUTS_200006B4,DIGFILTLUTS_LONG);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_DIGFILT_LUTS_8TO15,CONST_DIGFILT_LUTS_200006D4,DIGFILTLUTS_LONG);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_DIGFILT2_LUTS_0TO4,CONST_DIGFILT2_LUTS_20000794,DIGFILT2LUTS_LONG);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_DIGFILT2_LUTS_5TO9,CONST_DIGFILT2_LUTS_200007A8,DIGFILT2LUTS_LONG);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_RSSICFG_LUTS_0TO6,CONST_RSSICFG_LUTS_20000864,RSSICFGLUTS_LONG);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_UNKNOWN1,CONST_UNKNOWN1_200000C0,UNKNOWN1_LONG);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_UNKNOWN2,CONST_UNKNOWN2_40003E04,UNKNOWN2_LONG);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_UNKNOWN3,CONST_UNKNOWN3_20000AE0,UNKNOWN3_LONG);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_TXPACKET_DATA,CONST_OPEN_20000AF0,OPEN_LONG);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_IRQ1STATUS,CONST_IRQ1_OUT_4000380C,IRQSTATUS_LONG);//??IRQ1?????   ????
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    if(WORK_TEST == 0)
    {

        ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR_MSB(ADDR_TESTMODE0,GENERIC_PKT_TEST_MODES0_32bit_20000548);
//        ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_TESTMODE0,CONST_GENERIC_PKT_TEST_BUFF_20000548,TESTMODE0_LONG);//
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        DELAY_30U();
        ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR_MSB(RADIO_DIG_TX_CFG0,RADIO_DIG_TX_CFG0_32bit_20000304);
//        ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(RADIO_DIG_TX_CFG0,RADIO_DIG_TX_CFG0_20000304,DIGTXCFG0_LONG);//
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        DELAY_30U();
    }
    if(BREState == 1)
    {
        ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR_MSB(0x400041F8,0x00000000);
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        DELAY_30U();
        ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR_MSB(0x20000378,0x06c00043);
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        DELAY_30U();
    }
    ADF7030_CHANGE_STATE(STATE_CFG_DEV);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_CHANGE_STATE(STATE_PHY_OFF);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
}

void ADF7030_TRANSMITTING_FROM_POWEROFF(void)
{
    CG2214M6_USE_T;
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_CHANGE_STATE(STATE_PHY_ON);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_GENERIC_FIELDS,CONST_GENRIC_PACKET_200004F4+8,24);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_CHANNEL_FERQUENCY,CONST_DATA_PROFILE_200002E4+8,4);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_TXPACKET_DATA,CONST_TXPACKET_DATA_20000AF0,OPEN_LONG);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_CHANGE_STATE(STATE_PHY_TX);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    /*   while((PORTRead(ADF7030_GPIO3_PORT)&ADF7030_GPIO3_PIN)==0)//????????
    {
    DELAY_30U();
    }*/
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_IRQ0STATUS,CONST_IRQ1_OUT_4000380C,IRQSTATUS_LONG);//·¢ËÍÍê³É ÇåÖÐ¶ÏIRQ1
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_IRQ1STATUS,CONST_IRQ1_OUT_4000380C,IRQSTATUS_LONG);//·¢ËÍÍê³É ÇåÖÐ¶ÏIRQ1
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_CHANGE_STATE(STATE_PHY_ON);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
}
/*RECEIVE A SINGLE PACKET FROM POWER OFF*/
void ADF7030_RECEIVING_FROM_POWEROFF(void)
{
    CG2214M6_USE_R;
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_CHANGE_STATE(STATE_PHY_OFF);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_CHANGE_STATE(STATE_PHY_ON);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_GENERIC_FIELDS,CONST_GENRIC_PACKET_200004F4+8,24);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_CHANNEL_FERQUENCY,CONST_DATA_PROFILE_200002E4+8,4);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_CHANGE_STATE(STATE_PHY_RX);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
}

/*RECEIVE A SINGLE PACKET FROM POWER OFF*/
void ADF7030_CCA_FROM_POWEROFF(void)
{
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_CHANGE_STATE(STATE_PHY_ON);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_GENERIC_FIELDS,CONST_GENRIC_PACKET_200004F4+8,24);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_CHANNEL_FERQUENCY,CONST_DATA_PROFILE_200002E4+8,4);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_TXPACKET_DATA,CONST_TXPACKET_DATA_20000AF0,OPEN_LONG);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();
    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR_MSB(0x20000378,0x06c01043);
    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
    DELAY_30U();

    ADF7030_CHANGE_STATE(STATE_CMD_CCA);
    while(GET_STATUE_BYTE().FW_STATUS == 0);
    ADF7030_CHANGE_STATE(STATE_CMD_CCA);
    while(GET_STATUE_BYTE().FW_STATUS == 0);
    ClearWDT(); // Service the WDT
}

void RX_ANALYSIS(void)
{
    Signal_DATA_Decode(0);
//    ID_Decode_function();

 /*   if((SPI_RECEIVE_BUFF[11]==0x55)&&(SPI_RECEIVE_BUFF[12]==0x56))//open
    {
        YELLOWLED_ON();
        DELAY_XX();
        YELLOWLED_OFF();
    }
    if((SPI_RECEIVE_BUFF[11]==0x55)&&(SPI_RECEIVE_BUFF[12]==0x59))//stop
    {
        YELLOWLED_ON();
        DELAY_XX();
        YELLOWLED_OFF();
         DELAY_XX();
        YELLOWLED_ON();
        DELAY_XX();
        YELLOWLED_OFF();
    }
    if((SPI_RECEIVE_BUFF[11]==0x55)&&(SPI_RECEIVE_BUFF[12]==0x65))//close
    {
        YELLOWLED_ON();
        DELAY_XX();
        YELLOWLED_OFF();
         DELAY_XX();
        YELLOWLED_ON();
        DELAY_XX();
        YELLOWLED_OFF();
          DELAY_XX();
        YELLOWLED_ON();
        DELAY_XX();
        YELLOWLED_OFF();
    }*/
}


void SCAN_RECEIVE_PACKET(void)
{
    short Cache;
    char buf[10];
    if(ADF7030_GPIO3 == 1)
    {
        while(GET_STATUE_BYTE().CMD_READY == 0);
        DELAY_30U();
        ADF7030_READ_REGISTER_NOPOINTER_LONGADDR(0x40003808,6);//??7030????

        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        DELAY_30U();
        ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR_MSB(ADDR_IRQ0STATUS,0xffffffff);
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        DELAY_30U();
        ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR_MSB(ADDR_IRQ1STATUS,0xffffffff);
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        DELAY_30U();
        ADF7030_READ_REGISTER_NOPOINTER_LONGADDR(ADDR_RXPACKET_DATA,14);
        RedStutue = LEDFLASHASECONDFLAG | 0x80;
        RX_ANALYSIS(); //´¦ÀíÊý¾Ý
        while(ADF7030_GPIO3 == 1);
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        DELAY_30U();
        ADF7030_CHANGE_STATE(STATE_PHY_ON);
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        ADF7030_RECEIVING_FROM_POWEROFF();
        ADF7030_READ_REGISTER_NOPOINTER_LONGADDR(GENERIC_PKT_LIVE_LINK_QUAL, 6);
        Cache = (short)((ADF7030_RESIGER_VALUE_READ >> 11)&0xffe0);
        sprintf(buf,"-%ddBm\n",Cache/128) ;
    }
    else if ((ADF7030_GPIO2 == 1) && (GET_STATUE_BYTE().CMD_READY == 1))
    {
//        if ((Flag_RSSI_measure) && (RAM_RSSI_CNT < 100))
//        {
//            Flag_RSSI_measure = 0;
//            //ADF7030_READ_REGISTER_NOPOINTER_LONGADDR(GENERIC_PKT_LIVE_LINK_QUAL, 6);
//            Cache = (ADF7030_RESIGER_VALUE_READ >> 16);
//            if (Cache &0x0400)
//            {
//                Cache = ((~Cache + 1)&0x3ff);
//                RAM_RSSI_SUM -= Cache;
//                //Send_char(Cache>>2);
//            }
//            else
//                RAM_RSSI_SUM += Cache;
//            RAM_RSSI_CNT++;
//        }
    }
}
/**
****************************************************************************
* @Function : void WaitForADF7030_FIXED_DATA(void)
* @File     : ADF7030_1.c
* @Program  : none
* @Created  : 2017/4/18 by Xiaowine
* @Brief    : µÈ´ýADF7030Ð¾Æ¬¿É²Ù×÷(ÃüÁîÖ´ÐÐÍê³É/ÆäËû) ÄÚÖÃ¿´ÃÅ¹·
* @Version  : V1.0
**/
void WaitForADF7030_FIXED_DATA(void)
{
    while(((ADF7030_Read_OneByte&0x20)!=0x20)||((ADF7030_Read_OneByte&0x06)!=0x04))
    {
        DELAY_30U();
        ADF7030_FIXED_DATA();
        ClearWDT();
    }
}
/**
****************************************************************************
* @Function : ADF7030_1_STATUS_TYPE GET_STATUE_BYTE(void)
* @File     : ADF7030_1.c
* @Program  :
* @Created  : 2017/4/25 by Xiaowine
* @Brief    :
* @Version  : V1.0
**/
ADF7030_1_STATUS_TYPE GET_STATUE_BYTE(void)
{
    ADF7030_1_STATUS_TYPE StatusCache;
    DELAY_30U();
    ADF7030_FIXED_DATA();
    ClearWDT();
    StatusCache.VALUE = ADF7030_Read_OneByte;
    return StatusCache;
}
/**
****************************************************************************
* @Function : void TX_DataLoad(u32 IDCache,u8 CtrCmd,u8 *Packet)
* @File     : ADF7030_1.c
* @Program  : IDCache:ID CtrCmd:ÃüÁî *Packet£º·¢ËÍ°ü
* @Created  : 2017/4/18 by Xiaowine
* @Brief    :
* @Version  : V1.0
**/
void TX_DataLoad(u32 IDCache,u8 CtrCmd,u8 *Packet)
{
    u8 i;
    u16 CRCTemp = 0;
    CRCTemp = (IDCache & 0xffff) + (((IDCache >> 16)&0xff) + ((u16)CtrCmd << 8));
    for(i = 0;i < 24;i++)
    {
        *(Packet + (i/4)) <<= 2;
        *(Packet + (i/4)) |= ((IDCache &((u32)1<<i))? 2:1);
    }
    for(i = 24;i < 32;i++)
    {
        *(Packet + (i/4)) <<= 2;
        *(Packet + (i/4)) |= ((CtrCmd &((u8)1<<(i- 24)))? 2:1);
    }
    for(i = 32;i < 48;i++)
    {
        *(Packet + (i/4)) <<= 2;
        *(Packet + (i/4)) |= ((CRCTemp &((u16)1<<(i- 32)))? 2:1);
    }
    ClearWDT();
}
/**
****************************************************************************
* @Function : void TestCarrier(void)
* @File     : ADF7030_1.c
* @Program  :
* @Created  : 2017/4/19 by Xiaowine
* @Brief    : ²âÊÔ·¢ËÍÔØ²¨SUCESS
**/
void TestCarrier(u8 KeyVel)
{
    u8 data,i,num;
    char TextPlay;
    static u8 mode = 0;
    static u8 TestModeState = 0,SendIngFlag = 0;
    switch(KeyVel)
    {
      case KEY_Empty:break;
      case KEY_SW2_Down:{
        switch(mode)
        {
          case 0:RADIO_DIG_TX_CFG0_20000304[0]= 0x7c;mode = 1;TextPlay = ' ';break;   //FSK
          case 1:RADIO_DIG_TX_CFG0_20000304[0]= 0x7e;mode = 0;TextPlay = 'G';break; //GFSK
          default:break;
        }
        display_map_xy(4+10*6,8,5,8,char_Small+(TextPlay-' ')*5);
      }break;
      case KEY_SW3_Down:{
        if(TestModeState < 8)TestModeState++;
        if(TestModeState == 8)TestModeState = 0;
        num = TestModeState;
        for(i=0;i<3;i++)
        {
            data=num%10;
            num=num/10;
            display_map_xy(1+(2-i)*9,24,7,16,char_Medium+data*14);
        }
        ClearWDT(); // Service the WDT
      }break;
        default:break;
    }
    if((TestModeState != 0)&&(KeyVel == KEY_SW4_Down)&&(SendIngFlag == 0))//×ª»»µ½ÔØ²¨·¢ËÍ×´Ì¬
    {
        CONST_GENERIC_PKT_TEST_BUFF_20000548[2] =  TestModeState;//TestModeState;     //ÔØÈëTEST Ä£Ê½
        ClearWDT(); // Service the WDT
        ADF7030_WRITING_PROFILE_FROM_POWERON();
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        DELAY_30U();
        ADF7030_CHANGE_STATE(STATE_PHY_ON);
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        DELAY_30U();
        ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_GENERIC_FIELDS,CONST_GENRIC_PACKET_200004F4+8,24);
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        DELAY_30U();
        ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_CHANNEL_FERQUENCY,CONST_DATA_PROFILE_200002E4+8,4);
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        DELAY_30U();
        ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_TXPACKET_DATA,CONST_TXPACKET_DATA_20000AF0,OPEN_LONG);
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        DELAY_30U();
        ADF7030_CHANGE_STATE(STATE_PHY_TX);
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        SendIngFlag = 1;
        display_map_xy(8,50,5,8,char_Small+('T'-' ')*5);
        return;
    }
    if((SendIngFlag == 1)&&(KeyVel == KEY_SW4_Down))
    {
        ClearWDT(); // Service the WDT
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        ADF7030_CHANGE_STATE(STATE_PHY_ON);    //Í£Ö¹·¢ËÍ
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
//        ADF7030_WRITING_PROFILE_FROM_POWERON();
//        ADF7030_RECEIVING_FROM_POWEROFF();
        SendIngFlag = 0;
        display_map_xy(8,50,5,8,char_Small+(' '-' ')*5);
        return;
    }
}
/**
****************************************************************************
* @Function : void ReceiveTestModesCFG(void)
* @File     : ADF7030_1.c
* @Program  :
* @Created  : 2017/4/21 by Xiaowine
* @Brief    : ÅäÖÃ³É½ÓÊÕ²âÊÔ×´Ì¬  FROM_POWERON
* @Version  : V1.0
**/
void ReceiveTestModesCFG(void)
{
   // ADF7030_WRITING_PROFILE_FROM_POWERON();
    ADF7030_CCA_FROM_POWEROFF();
}
/**             SUCESS
****************************************************************************
* @Function : void ModeTrans(u8 KeyVavle)
* @File     : ADF7030_1.c
* @Program  :
* @Created  : 2017/4/25 by Xiaowine
* @Brief    :
* @Version  : V1.0
**/
void ModeTrans(u8 KeyVavle)
{
    static u8 ModeStatus = 0,SendIngFlag = 0;
    u32 num;
    u8 data,i;
    if((ModeStatus != 0)&&(KeyVavle == ModeStatus))
    {
        while(GET_STATUE_BYTE().CMD_READY != 1);
        RadioChangeState(STATE_PHY_ON);
//        RadioChangeState(STATE_PHY_OFF);
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        DELAY_30U();
        SendIngFlag = 0;
        ModeStatus = 0;
        return;
    }
    if(ModeStatus == 0)
    {
        switch(KeyVavle)
        {
          case KEY_Empty:break;
          case KEY_SW2_Down:{
              CONST_GENERIC_PKT_TEST_BUFF_20000548[2] =  TestTXCarrier;
              ModeStatus = KEY_SW2_Down;
            } break;//TXTest  Carrier
          case KEY_SW3_Down:{
              CONST_GENERIC_PKT_TEST_BUFF_20000548[2] =  TestTx_PreamblePattern;
              ModeStatus = KEY_SW3_Down;
            }break;//TXTest  Transmit preamble pattern
          case KEY_SW4_Down:{
              ReceiveTestModesCFG();
              ModeStatus = KEY_SW4_Down;
          }break;//
          default:break;
        }
    }

    if(((ModeStatus == KEY_SW2_Down)||(ModeStatus == KEY_SW3_Down))&&(SendIngFlag == 0))//×ª»»µ½ÔØ²¨·¢ËÍ×´Ì¬
    {
        num = CONST_GENERIC_PKT_TEST_BUFF_20000548[2];
        for(i=0;i<2;i++)
        {
            data=num%10;
            num=num/10;
            display_map_xy(1+(1-i)*9,24,7,16,char_Medium+data*14);
        }
        ClearWDT(); // Service the WDT
        ADF7030_WRITING_PROFILE_FROM_POWERON();
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        DELAY_30U();
        ADF7030_CHANGE_STATE(STATE_PHY_ON);
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        DELAY_30U();
        ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_GENERIC_FIELDS,CONST_GENRIC_PACKET_200004F4+8,24);
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        DELAY_30U();
        ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_CHANNEL_FERQUENCY,CONST_DATA_PROFILE_200002E4+8,4);
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        DELAY_30U();
        ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_TXPACKET_DATA,CONST_TXPACKET_DATA_20000AF0,OPEN_LONG);
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        DELAY_30U();
        ADF7030_CHANGE_STATE(STATE_PHY_TX);
        WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
        SendIngFlag = 1;
        return;
    }
    if((ModeStatus == KEY_SW4_Down)&&(TIMER300ms >= 20))
    {
        DELAY_30U();
        while(GET_STATUE_BYTE().CMD_READY != 1);
        DELAY_30U();
        ADF7030_READ_REGISTER_NOPOINTER_LONGADDR(PROFILE_CCA_READBACK,6);
        num = (ADF7030_RESIGER_VALUE_READ & 0x07ff);//>>16;
        if(num &0x00000400)
        {
            num = ((~num) + 1) & 0x000003ff;
            display_map_xy(0,20,5,8,char_Small+('-'-' ')*5);
        }else display_map_xy(0,20,5,8,char_Small+(' '-' ')*5);
        DELAY_30U();
        num /= 4;
        for(i=0;i<4;i++)
        {
            data = num % 10;
            num /= 10;
            display_map_xy(90+(3-i)*9,16,7,16,char_Medium+data*14);
        }
        TIMER300ms = 0;
    }
}

/**
 ****************************************************************************
 * @Function : void TestFunV2(u8 KeyVel)
 * @File     : ADF7030_1.c
 * @Program  : KeyVel: °´¼üÖµ
 * @Created  : 2017/5/2 by Xiaowine
 * @Brief    : °´¼ü ±íµ¥ÇÐ»»
 * @Version  : V1.0
**/
void TestFunV2(u8 KeyVel)
{
    static u8 StatePoint = 0,PowerdBm = 0,TestState = 0,SendFlag = 0,CCAFlag = 0;
    char TestStatewords[] = {'R','C','+','-','P'};
    u8 Cache,data,i;
    u32 num;
    if(StateReadTimer == 0)
    {
        Radio_State = ADF7030_GET_FW_STATE();
        DELAY_30U();
        while(GET_STATUE_BYTE().CMD_READY != 1);
        DELAY_30U();
        ADF7030_READ_REGISTER_NOPOINTER_LONGADDR(0X4000380C,6);//PROFILE_CCA_READBACK,6);
        CCA_READBACK_Cache = ADF7030_RESIGER_VALUE_READ;
        StateReadTimer = 500;
    }
    if(SendFlag == 0)
    {
        if(KeyVel == KEY_SW2_Down)
        {
            display_map_xy(1, 9*(StatePoint+1),5,8,char_Small);
            if(StatePoint > 4)StatePoint = 0;
            else StatePoint++;
            display_map_xy(1, 9 * (StatePoint + 1),5,8,char_Small + ('*' - ' ') * 5);
        }
        else if(KeyVel == KEY_SW3_Down)
        {
            switch(StatePoint)
            {
              case 0:{                               //GFSK
                    RADIO_DIG_TX_CFG0_32bit_20000304 ^= 2;
                    Cache = (RADIO_DIG_TX_CFG0_32bit_20000304 & 0x02) >> 1;
                    display_map_xy(52,9,5,8,char_Small + (FilterChar[Cache][0] - ' ')*5);
                    break;
                }
              case 1:{                               //PAx
                    RADIO_DIG_TX_CFG0_32bit_20000304 ^= 0x40000000;
                    Cache = (RADIO_DIG_TX_CFG0_32bit_20000304 >> 30) & 1;
                    display_map_xy(52,18,5,8,char_Small + ('1' - ' ' + Cache)*5);
                    RADIO_DIG_TX_CFG0_32bit_20000304 &= 0xff000fff;
                    RADIO_DIG_TX_CFG0_32bit_20000304 |= ((u32)PA_POWER_OUT[Cache][PowerdBm]<<12);
                    break;
                }
              case 2:{                              //dBm
                  if(PowerdBm > 16)PowerdBm = 0;
                  else PowerdBm++;
                  Cache = PowerdBm / 10;
                  display_map_xy(52,27,5,8,char_Small + ('0' - ' ' + Cache)*5);
                  Cache = PowerdBm % 10;
                  display_map_xy(58,27,5,8,char_Small + ('0' - ' ' + Cache)*5);
                  Cache = (RADIO_DIG_TX_CFG0_32bit_20000304 >> 30) & 1;
                  RADIO_DIG_TX_CFG0_32bit_20000304 &= 0xff000fff;
                  RADIO_DIG_TX_CFG0_32bit_20000304 |= ((u32)PA_POWER_OUT[Cache][PowerdBm] << 12);
                  break;
              }
              case 3:{                               //TX_Mode
                  if(TestState > 3)TestState = 0;
                  else TestState++;
                  GENERIC_PKT_TEST_MODES0_32bit_20000548 &= 0xfff8ffff;
                  GENERIC_PKT_TEST_MODES0_32bit_20000548 |= ((u32)TEST_MODES0_para[TestState] << 16);
                  display_map_xy(52,36,5,8,char_Small+(TestStatewords[TestState] - ' ')*5);
                  break;
              }
              case 4:{                               //BER
                  if(BREState == 1)BREState = 0;
                  else BREState = 1;
                  display_map_xy(52,45,5,8,char_Small + ('0' - ' ' + BREState)*5);
                  break;
                }
              case 5:{                               //CCA
                  if(CCAFlag == 1)CCAFlag = 0;
                  else CCAFlag = 1;
                  display_map_xy(52,54,5,8,char_Small + ('0' - ' ' + CCAFlag)*5);
                  break;
              }
              default:break;
            }
        }
        else if(KeyVel == KEY_SW4_Down)
        {
            if(SendFlag == 0)
            {
                if(TestState != 0)
                {
                    CG2214M6_USE_T;
                    ADF7030_WRITING_PROFILE_FROM_POWERON();
                    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
                    DELAY_30U();
                    ADF7030_CHANGE_STATE(STATE_PHY_ON);
                    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
                    DELAY_30U();
                    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_GENERIC_FIELDS,CONST_GENRIC_PACKET_200004F4+8,24);
                    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
                    DELAY_30U();
                    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_CHANNEL_FERQUENCY,CONST_DATA_PROFILE_200002E4+8,4);
                    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
                    DELAY_30U();
                    ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(ADDR_TXPACKET_DATA,CONST_TXPACKET_DATA_20000AF0,OPEN_LONG);
                    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
                    DELAY_30U();
                    ADF7030_CHANGE_STATE(STATE_PHY_TX);
                    WaitForADF7030_FIXED_DATA();  //µÈ´ýÐ¾Æ¬¿ÕÏÐ/¿É½ÓÊÜCMD×´Ì¬
                }else{
                    if(CCAFlag == 0)
                    {
                        ADF7030_WRITING_PROFILE_FROM_POWERON();
                        ADF7030_RECEIVING_FROM_POWEROFF();
                        if(BREState == 1){RedStutue = LEDFLASHFLAG | 0x80;}
                    }
                    else{
                        ADF7030_WRITING_PROFILE_FROM_POWERON();

                        ADF7030_CCA_FROM_POWEROFF();
                    }
                }
                display_map_58_6(10,63,7,"Startup");
                SendFlag = 1;
            }
        }
    }
    else
    {
        if(TestState == 0)
        {
            if(CCAFlag == 0)
            {
                if(BREState == 1){RF_BRE_Check();}
                else SCAN_RECEIVE_PACKET();
            }else if(ADF7030_GET_FW_STATE() == PHY_ON)
            {

                while(GET_STATUE_BYTE().CMD_READY == 0);
                DELAY_30U();
                ADF7030_READ_REGISTER_NOPOINTER_LONGADDR(0x2000037C,6);//??7030????
                num = (((~ADF7030_RESIGER_VALUE_READ) + 1) & 0x7ff);

                for(i=0;i<4;i++)
                {
                    data = num % 10;
                    num /= 10;
                    display_map_xy(60 + (3 - i) * 6,54,5,8,char_Small + ('0' - ' ' + data)*5);
                }
                display_map_58_6(10,63,7,"END    ");
                SendFlag = 0;
            }

        }
        if(KeyVel == KEY_SW4_Down)
        {
            display_map_58_6(10,63,7,"END    ");
            ADF7030_GET_MISC_FW();
            SendFlag = 0;
        }
    }
}


