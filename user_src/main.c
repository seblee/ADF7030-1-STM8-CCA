/**
  ******************************************************************************
  * @file    Project/STM8L15x_StdPeriph_Template/main.c
  * @author  MCD Application Team
  * @version V1.5.0
  * @date    13-May-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include  <iostm8l151g4.h>				// CPU型号
//#include "stm8l15x.h"
#include "Pin_define.h"		// 管脚定义
#include "initial.h"		// 初始????? 预定?????#include "ram.h"		// RAM定义
#include "eeprom.h"
#include "ADF7030_1.h"
#include "Timer.h"		// 定时?????#include "eeprom.h"		// eeprom
#include "uart.h"		// uart
#include "lcd.h"		// lcd
#include "stdlib.h"
#include "time.h"
#include "ID_Decode.h"
/** @addtogroup STM8L15x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */

UINT16 rand_data=0;
u8 FLAG_SW10=0;
u16 KEY_COUNT=0;
void main(void)
{
    u8 Key_Value;
    _DI();		// 关全局中断
    RAM_clean();       // 清除RAM
    VHF_GPIO_INIT();
    SysClock_Init();
    InitialFlashReg();
    eeprom_sys_load();
    EXIT_init();
    TIM4_Init();
    UART1_INIT();  // UART1 for PC Software
    _EI();       // 允许中断
    WDT_init();
    lcd_init();
    ClearWDT(); // Service the WDT
    ADF7030Init();
    //beep_init();
    srand((unsigned) time(NULL));
    TX_DataLoad(10010101,OpenMode,&CONST_TXPACKET_DATA_20000AF0[0]);
    while(WORK_TEST == 0)//测试模式
    {
        ClearWDT(); // Service the WDT
        LCDTestDisplay();
//        TestCarrier(KEY_SCAN(0));
//        ModeTrans(KEY_SCAN(0));
        TestFunV2(KEY_SCAN(0));
        LEDCtr();

    }
    while(1)
    {
        LEDCtr();
        ClearWDT(); // Service the WDT
        lcd_desplay();
        Key_Value = KEY_SCAN(0);
        if(Key_Value != KEY_Empty)
        {
            switch(Key_Value)
            {
              case KEY_Empty:break;
              case KEY_SW2_Down:TX_DataLoad(1,OpenMode,&CONST_TXPACKET_DATA_20000AF0[0]);break;
              case KEY_SW3_Down:TX_DataLoad(1,StopMode,&CONST_TXPACKET_DATA_20000AF0[0]);break;
              case KEY_SW4_Down:TX_DataLoad(1,CloseMode,&CONST_TXPACKET_DATA_20000AF0[0]);break;
              default:break;
            }
            if(FLAG_SW10 == 0)
            {
                ADF7030_WRITING_PROFILE_FROM_POWERON();
                ADF7030_TRANSMITTING_FROM_POWEROFF();
                YELLOWLED_OFF();
                FLAG_SW10 = 1;
            }
        }
        else
        {
            if(FLAG_SW10==1)
            {
                KEY_COUNT++;
                if(KEY_COUNT > 500)
                {
                    KEY_COUNT =0 ;
                    FLAG_SW10 =0;
                    ADF7030_WRITING_PROFILE_FROM_POWERON();
                    ADF7030_RECEIVING_FROM_POWEROFF();
                    // ADF7030_ACC_FROM_POWEROFF();
                }
            }
        }

//        ID_Decode_IDCheck();
        SCAN_RECEIVE_PACKET();

    }

//    while (1)
//    {
//        rand_data=rand();
//        ClearWDT(); // Service the WDT
//        /*
//        ID_Decode_IDCheck();
//        if(time_Login_exit_256==0)ID_Decode_OUT();
//        Freq_Scanning();
//        ID_learn();
//        if(rxphase!=0)READ_RSSI_avg();
//        lcd_desplay();
//
//        if((RAM_rssi_AVG>=60)||(FG_Receiver_LED_RX==1))LED_YELLOW=1;   //26   35
//        else if((RAM_rssi_AVG<=59)&&(FG_Receiver_LED_RX==0))LED_YELLOW=0;  //25  34
//          */
//    }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
