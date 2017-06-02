/****************************************************************************
 *                    ADF7021 #define Functions                             *
 ****************************************************************************/
/***********************************************************************/
/*  FILE        :adf7012.h                                             */
/*  DATE        :Mar, 2014                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8L151G6     Crystal: 16M HSI                       */
/*  DESCRIPTION :                                                      */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/

void dd_set_TX_mode(void);
void dd_set_TX_mode_carrier(void);
void dd_set_TX_mode_1010pattern(void);
void dd_write_7021_reg(unsigned char* reg_bytes);
void dd_set_ADF7021_Power_on(void);
void dd_set_RX_mode(void);
void dd_set_ADF7021_Freq(void);
void dd_set_RX_mode_test(void);
ADF70XX_REG_T dd_read_7021_reg(UINT8 readback_config);
void dd_read_RSSI(void);
void READ_RSSI_avg(void);