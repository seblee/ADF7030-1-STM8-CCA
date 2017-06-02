#ifndef __RAM_H__
#define __RAM_H__
//CPU?????
//?????ADF030???????
//#define TX_TEST_CARRIER_MODE 0
#include "initial.h" // 初始化  预定义

extern volatile union {
	unsigned char BYTE;
	struct
	{
		unsigned char Bit0 : 1;
		unsigned char Bit1 : 1;
		unsigned char Bit2 : 1;
		unsigned char Bit3 : 1;
		unsigned char Bit4 : 1;
		unsigned char Bit5 : 1;
		unsigned char Bit6 : 1;
		unsigned char Bit7 : 1;
	} BIT;
} FLAG_test1;
//************************************************
#define FLAG_test1_BYTE FLAG_test1.BYTE
//------------------------------------------------
#define BIT_SIO FLAG_test1.BIT.Bit0
#define FG_auto_out FLAG_test1.BIT.Bit1
#define FG_OUT_OPEN_CLOSE FLAG_test1.BIT.Bit2 //历史记录   误码率测试用
											  //    #define		FG_auto_outbz		FLAG_test1.BIT.Bit3
#define FG_auto_open_time FLAG_test1.BIT.Bit4
#define FG_auto_manual_mode FLAG_test1.BIT.Bit5 //1=auto,0=manual
#define FG_Receiver_LED_RX FLAG_test1.BIT.Bit6
#define FG_First_auto FLAG_test1.BIT.Bit7
//************************************************

extern UINT8 SIO_cnt;
extern UINT8 SIO_buff[16];
extern UINT8 SIO_DATA[16];

extern UINT8 TIME_10ms;
extern UINT16 TIMER1s;
extern UINT16 TIMER300ms;
extern UINT16 TIMER18ms;
extern UINT8 TIMER250ms_STOP;
extern UINT16 TIME_auto_out;
extern UINT16 TIME_auto_close;
extern UINT16 time_3sec;
extern UINT32 ID_Receiver_DATA[256]; //写入EEPROM ID的数据
extern UINT16 ID_DATA_PCS;
extern u8 Count_key_SW3;
extern u8 Display_key_SW3;

/**********LCD******************/
extern uFLAG FlagLCDUpdate;

#define LCDUpdateIDFlag FlagLCDUpdate.BIT.Bit0
#define LCDUpdateRISSFlag FlagLCDUpdate.BIT.Bit1
#define LCDFirstDisplayFlag FlagLCDUpdate.BIT.Bit2
/**********RSSI*********************/
extern u16 LCDRSSI;
extern u16 RAM_RSSI_SUM;
extern u8 RAM_RSSI_CNT;
extern u8 RAM_RSSI_AVG;

#define SPI_SEND_BUFF_LONG 300
#define SPI_REV_BUFF_LONG 40

extern const u8 Radio_Memory_Configuration[];
#define PROFILE_LONG 264
extern const UINT8 CONST_DATA_PROFILE_200002E4[PROFILE_LONG];
#define OPEN_LONG 12
extern const u8 CONST_OPEN_20000AF0[OPEN_LONG];
extern UINT8 CONST_TXPACKET_DATA_20000AF0[OPEN_LONG];
#define GENRIC_LONG 108
extern const UINT8 CONST_GENRIC_PACKET_200004F4[GENRIC_LONG];
#define DIGFILTLUTS_LONG 32
extern const UINT8 CONST_DIGFILT_LUTS_200006B4[DIGFILTLUTS_LONG];
extern const UINT8 CONST_DIGFILT_LUTS_200006D4[DIGFILTLUTS_LONG];
#define ANAFILTLUTS_LONG 24
extern const UINT8 CONST_ANAFILT_LUTS_2000060C[ANAFILTLUTS_LONG];
extern const UINT8 CONST_ANAFILT_LUTS_20000624[ANAFILTLUTS_LONG];
extern const UINT8 CONST_ANAFILT_LUTS_2000063C[ANAFILTLUTS_LONG];
#define DIGFILT2LUTS_LONG 20
extern const UINT8 CONST_DIGFILT2_LUTS_20000794[DIGFILT2LUTS_LONG];
extern const UINT8 CONST_DIGFILT2_LUTS_200007A8[DIGFILT2LUTS_LONG];
#define RSSICFGLUTS_LONG 28
extern const UINT8 CONST_RSSICFG_LUTS_20000864[RSSICFGLUTS_LONG];
#define UNKNOWN1_LONG 4
extern const UINT8 CONST_UNKNOWN1_200000C0[UNKNOWN1_LONG];
#define UNKNOWN2_LONG 16
extern const UINT8 CONST_UNKNOWN2_40003E04[UNKNOWN2_LONG];
#define UNKNOWN3_LONG 16
extern const UINT8 CONST_UNKNOWN3_20000AE0[UNKNOWN3_LONG];
#define IRQSTATUS_LONG 4
extern const UINT8 CONST_IRQ0_OUT_40003808[IRQSTATUS_LONG];
extern const UINT8 CONST_IRQ1_OUT_4000380C[IRQSTATUS_LONG];
#define TESTMODE0_LONG 4
extern const UINT8 CONST_GENERIC_PKT_TEST_MODES0_20000548[TESTMODE0_LONG];
extern u8 CONST_GENERIC_PKT_TEST_BUFF_20000548[TESTMODE0_LONG];
extern u32 GENERIC_PKT_TEST_MODES0_32bit_20000548;
extern const u8 TEST_MODES0_para[5];

#define DIGTXCFG0_LONG 4
extern u8 RADIO_DIG_TX_CFG0_20000304[DIGTXCFG0_LONG];
extern u32 RADIO_DIG_TX_CFG0_32bit_20000304;
#define AFCCONFIG_LONG 4
extern const u8 CONST_AFC_Configuration_400041F8[4];
extern u16 PA_POWER_OUT[2][18];
void SPI_INIT(void);
UINT32 ADF7030_GET_MISC_FW(void); //??MISC_FW?????
void ADF7030_WRITING_PROFILE_FROM_POWERON(void);
void ADF7030_TRANSMITTING_FROM_POWEROFF(void);
void ADF7030_RECEIVING_FROM_POWEROFF(void);
void SCAN_RECEIVE_PACKET(void);
u32 ConfigurationLen(void);

#endif
