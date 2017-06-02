#ifndef __ADF7030_1_H__
#define __ADF7030_1_H__

#include "ram.h"

#define STATE_PHY_SLEEP  0X80
#define STATE_PHY_OFF    0X81
#define STATE_PHY_ON     0X82
#define STATE_PHY_RX     0X83
#define STATE_PHY_TX     0X84
#define STATE_CFG_DEV    0X85//CONFIG ADF7030
#define STATE_CMD_CCA    0X86
#define STATE_CMD_DO_CAL 0X89
#define STATE_CMD_MON    0X8A
/******************************************************/
#define PHY_SLEEP                     0x00
#define PHY_OFF                       0x01
#define PHY_ON                        0x02
#define PHY_RX                        0x03
#define PHY_TX                        0x04
#define DO_CFG_DEV                    0x05
#define PHY_CCA                       0x06
#define PHY_PATCH                     0x07
#define DO_IRCAL                      0x08
#define DO_CAL                        0x09
#define DO_TEMP_MEAS                  0x0A
#define DO_XTAL_TCAL                  0x0B
#define DO_LFRC_CAL                   0x0C

/*! \cond PRIVATE */
//Debug states
#define DO_ROMCRC_CONTINUOUS          0x0D
#define DO_RAMCRC_CONTINUOUS          0x0E
#define DO_MCRCRC_CONTINUOUS          0x0F
#define DO_NOP_FOREVER                0x10
#define DO_SNOOP_TESTMODES_LOOPBACK   0x11
#define D0_ROMCRC_SOFT_CONTINUOUS     0x12
#define D0_RAMCRC_SOFT_CONTINUOUS     0x13
#define D0_MCRCRC_SOFT_CONTINUOUS     0x14
#define D0_CAPTURE_RX_CONTINUOUS      0x15
#define DO_ANC_PLL_CAL                0x16
#define DO_ADC_NOTCH_CAL              0x17
#define DO_OCL_CAL                    0x18
#define DO_FILT_CAL                   0x19
#define DO_VCO_KV_CAL                 0x1A
#define DO_HFRC_OFF                   0x1D
#define DO_ANC_PLL_ON                 0x1E
#define DO_PHY_ERROR_HANDLER          0x1F
/*! \endcond */

/**************TEST MODE******************************/
#define TestDisabled                    0x00
#define TestTXCarrier                   0x01
#define TestTx_Reduce_FDEV_2FSK_OFF_OOK 0x02
#define TestTx_Reduce_FDEV_MAX_4FSK     0x03
#define TestTx_Plus_FDEV_2FSK_ON_OOK    0x04
#define TestTx_Plus_FDEV_MAX_4FSK       0x05
#define TestTx_PreamblePattern          0x06
#define TestTx_PN9                      0x07

/**************************************************/
#define ADDR_MISC_FW  				0X400042B4
#define ADDR_PROFILE_START      	0X200002E4
#define ADDR_GENERIC_START      	0X200004F4
#define ADDR_DIGFILT_LUTS_0TO7  	0x200006B4
#define ADDR_DIGFILT_LUTS_8TO15 	0X200006D4
#define ADDR_ANAFILT_LUTS_0TO5  	0X2000060C
#define ADDR_ANAFILT_LUTS_6TO11 	0X20000624
#define ADDR_ANAFILT_LUTS_12TO17 	0X2000063C
#define ADDR_DIGFILT2_LUTS_0TO4   	0X20000794
#define ADDR_DIGFILT2_LUTS_5TO9   	0X200007A8
#define ADDR_RSSICFG_LUTS_0TO6    	0X20000864
#define ADDR_UNKNOWN1        		0x200000C0
#define ADDR_UNKNOWN2         		0x40003E04
#define ADDR_UNKNOWN3         		0x20000AE0
#define ADDR_IRQ0STATUS       		0x40003808
#define ADDR_IRQ1STATUS       		0x4000380C
#define ADDR_TXPACKET_DATA    		0X20000AF0
#define ADDR_RXPACKET_DATA    		0X20000C18
#define ADDR_TESTMODE0        		0X20000548
#define ADDR_GENERIC_FIELDS     	0X200004FC
#define ADDR_CHANNEL_FERQUENCY  	0x200002EC
#define RADIO_DIG_TX_CFG0         	0x20000304
#define PROFILE_RADIO_AFC_CFG2      0x20000320
#define AFC_CONFIG                  0x400041F8
#define GENERIC_PKT_LIVE_LINK_QUAL  0x20000538
#define PROFILE_CCA_READBACK        0x2000037C
#define RADIO_AFC_CFG1              0x2000031C


extern u8   RX_COUNT;
extern u8   SPI_RECEIVE_BUFF[SPI_REV_BUFF_LONG];
extern u32   SPI_Receive_DataForC[6];
extern u32  ADF7030_RESIGER_VALUE_READ;
extern u8   ADF7030_Read_OneByte;
extern u16  Head_0x5515_or_0x5456;

extern UINT32 DATA_Packet_ID;
extern UINT8  DATA_Packet_Control;
extern UINT8  DATA_Packet_Contro_buf;   //2015.3.24ÐÞÕý


void DELAY_30U(void);

void ADF7030Init(void);

void ADF7030_FIXED_DATA(void);
void ADF7030_CHANGE_STATE(u8 x_state);
u32 ADF7030_READ_REGISTER_NOPOINTER_LONGADDR(u32 x_ADDR,u8 x_fnum);
void WaitForADF7030_FIXED_DATA(void);
void TX_DataLoad(u32 IDCache,u8 CtrCmd,u8 *Packet);
void TestCarrier(u8 mode);
void ADF7030_CCA_FROM_POWEROFF(void);
ADF7030_1_STATUS_TYPE GET_STATUE_BYTE(void);
u8 ADF7030_GET_FW_STATE(void);
void ModeTrans(u8 KeyVavle);
void TestFunV2(u8 KeyVel);
void ADF7030_WRITE_REGISTER_NOPOINTER_LONGADDR(u32 x_ADDR,const u8 *x_data,u16 x_long);




#endif

