/***********************************************************************/
/*  FILE        :ID_Decode.h                                           */
/*  DATE        :Mar, 2014                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8L151G6     Crystal: 16M HSI                       */
/*  DESCRIPTION :                                                      */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/
#ifndef __STM8L15x_IT_H
#define __STM8L15x_IT_H

#define DataForC_Done BX_RecevieBlockFlag.BIT.Bit2

extern volatile uFLAG FLAG0;

//************************************************
#define FLAG0_BYTE FLAG0.BYTE
//------------------------------------------------
#define FLAG_Receiver_IDCheck FLAG0.BIT.Bit0
#define FLAG_Signal_DATA_OK FLAG0.BIT.Bit1
#define FLAG_APP_RX FLAG0.BIT.Bit2
#define FLAG_IDCheck_OK FLAG0.BIT.Bit3
#define FLAG_ID_Erase_Login FLAG0.BIT.Bit4
#define FLAG_ID_Erase_Login_PCS FLAG0.BIT.Bit5
#define FLAG_ID_Login FLAG0.BIT.Bit6
#define FLAG_ID_Login_OK FLAG0.BIT.Bit7
//************************************************
#define OpenMode (u8)(0x08)
#define StopMode (u8)(0x04)
#define CloseMode (u8)(0x02)

void EXIT_init(void);
void ID_Decode_function(void);
void ID_Decode_IDCheck(void);
void Signal_DATA_Decode(UINT8 NUM_Type);
void eeprom_IDcheck(void);
void BEEP_and_LED(void);
void ID_Decode_OUT(void);
void Receiver_BEEP(void);
void Freq_Scanning(void);
extern void DataReceive(void);

#endif
