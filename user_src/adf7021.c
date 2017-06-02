/****************************************************************************
 *                    ADF7021 Control Functions                             *
 ****************************************************************************/
/***********************************************************************/
/*  FILE        :adf7012.c                                             */
/*  DATE        :Mar, 2014                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8L151G6     Crystal: 16M HSI                       */
/*  DESCRIPTION :                                                      */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/

#include  <iostm8l151g4.h>				// CPU型号 
#include "Pin_define.h"		// 管脚定义
#include "initial.h"		// 初始化  预定义
#include "ram.h"		// RAM定义

void dd_write_7021_reg(unsigned char* reg_bytes)
{
    UINT8 i, j;
    UINT8 byte;

    ADF7021_SLE = 0;
    ADF7021_SCLK = 0;


    /* Clock data out MSbit first */
//#ifdef _BIG_ENDIAN_
//    for (i=0; i<=3; i++)
//#else
//    for (i=3; i>=0; i--)
//#endif
    for (i=0; i<=3; i++)
    {
        byte = reg_bytes[i];

        for (j=8; j>0; j--)
        {
            ADF7021_SCLK = 0;
            if (byte & 0x80) ADF7021_SDATA = 1;
            else ADF7021_SDATA = 0;
	    Delayus(1);
	    Delayus(1);
            ADF7021_SCLK = 1;
	    Delayus(1);
	    Delayus(1);
            byte += byte; // left shift 1
        }
        ADF7021_SCLK = 0;
    }


    /* Strobe the latch */

    ADF7021_SLE = 1;
    ADF7021_SLE = 1; // Slight pulse extend
    ADF7021_SDATA = 0;
    ADF7021_SLE = 0;

    /* All port lines left low */

}

ADF70XX_REG_T dd_read_7021_reg(UINT8 readback_config)
{
    ADF70XX_REG_T register_value;
    INT8 i, j;
    UINT8 byte;



    /* Write readback and ADC control value */
    register_value.whole_reg = (readback_config & 0x1F) << 4;
    register_value.whole_reg |= 7; // Address the readback setup register

    dd_write_7021_reg(&register_value.byte[0]);

    register_value.whole_reg = 0;


    /* Read back value */

    ADF7021_SDATA = 0;
    ADF7021_SCLK = 0;
    ADF7021_SLE = 1;

   //Clock in first bit and discard 
    ADF7021_SCLK = 1;
    byte = 0; // Slight pulse extend
    ADF7021_SCLK = 0;


    /* Clock in data MSbit first */
    for (i=2; i<=3; i++)
    {
        for (j=8; j>0; j--)
        {
            ADF7021_SCLK = 1;
            byte += byte; // left shift 1
            ADF7021_SCLK = 0;

          if (ADF7021_SREAD) byte |= 1;
        }

        register_value.byte[i] = byte;

		Delayus(1);	//wait for a bit time
	    		
	}//for i=2 : 3;

	ADF7021_SCLK = 1;
	ADF7021_SCLK = 0;

/*
	ADF7021_SCLK = 1;
	ADF7021_SCLK = 0;
*/
    ADF7021_SLE = 0;
    // All port lines left low  

    return register_value;
}

void dd_set_TX_mode(void)
{
  UINT16 i;
//	ADF70XX_REG_T register_value;
//        //write R1, turn on VCO
//	register_value.whole_reg = 0x031BD011;
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delay100us(8);		//delay 800us
//        
//	//write R3, turn on TX/RX clocks
//	register_value.whole_reg = 0x29915CD3;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//
//	//write R0, turn on PLL
//	register_value.whole_reg = 0x015759A0;
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(40);		//delay 40us
//
//	//write R2, turn on PA
//	register_value.whole_reg = 0x06B6882;			//Ramp Rate = 16 codes/bit, TX level = 2;
////	register_value.whole_reg = 0x006FF582;			//max power TX
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//        
//	register_value.whole_reg = 0x00268614;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//        
//	register_value.whole_reg = 0x00001915;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//        
//	register_value.whole_reg = 0x0504C986;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//        
//	register_value.whole_reg = 0x329668EA;
//	dd_write_7021_reg(&register_value.byte[0]);
  
  
  
	ADF70XX_REG_T register_value;
          //dd_set_ADF7021_ReInitial();
        //write R1, turn on VCO
	register_value.whole_reg = ROM_adf7012_value[1].whole_reg;//0x031B5011;//0x031BD011;      //2013年11月22日修改  天线驱动偏执电流   2.1mA-->1.5mA
	//register_value.whole_reg = 0x031B5091;    //Colck OUT 5.00MHz
	dd_write_7021_reg(&register_value.byte[0]);
	//Delayus(800);		//delay 800us
        for(i=0;i<20;i++)  Delayus(122);   //40us


	
	//write R3, turn on TX/RX clocks
	register_value.whole_reg = 0x29915CD3;//0x2991A0D3;
	dd_write_7021_reg(&register_value.byte[0]);
        Delayus(122);		//delay 40us

	//write R0, turn on PLL
	//register_value.whole_reg = 0x0154DC30;       //CH=426.075MHz
        //register_value.whole_reg = 0x01575710;   //CH=429.175MHz
        //register_value.whole_reg = 0x01576140;//CH=429.225MHz
	register_value.whole_reg = 0x0154DC30;       //CH=426.075MHz
        //if(TX_Freq_CH==1)register_value.whole_reg = 0x0154DC30;       //CH=426.075MHz
//        if(TX_Freq_CH==2)register_value.whole_reg = 0x01575710;   //CH=429.175MHz
//        else if(TX_Freq_CH==4)register_value.whole_reg = 0x01575C30;  //CH=429.200MHz
//        else if(TX_Freq_CH==6)register_value.whole_reg = 0x01576140;//CH=429.225MHz
	dd_write_7021_reg(&register_value.byte[0]);
	Delayus(122);		//delay 40us

	//write R2, turn on PA
	register_value.whole_reg = 0x00566882;//0x00536882;//0x006B6882;	//2013年11月22日修改	TX频偏 1.6K 2FSK  功率:51（10dBM） （0x00566882）
        //register_value.whole_reg = 0x006E6882;                     //2013年11月29日修改  TX频偏 2K 2FSK  功率:51（10dBM）       （0x006E6882）
	dd_write_7021_reg(&register_value.byte[0]);
        Delayus(122);		//delay 40us

	register_value.whole_reg = 0x00289A14;//0x00268614;       //2013年11月22日修改  频偏 1.6K 2FSK correlator（0x00289A14）-->2K 2FSK correlator（0x00268614）
        //register_value.whole_reg = 0x00200004;                    //2013年11月29日修改   2FSK linear（0x00200004）   频偏不设置
	dd_write_7021_reg(&register_value.byte[0]);
        Delayus(122);		//delay 40us

//	register_value.whole_reg = 0x00001915;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//
//	register_value.whole_reg = 0x0504C986;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//
//	register_value.whole_reg = 0x329668EA;
//	dd_write_7021_reg(&register_value.byte[0]);  
}

void dd_set_TX_mode_carrier(void)
{
  UINT16 i;
//	ADF70XX_REG_T register_value;
//        //write R1, turn on VCO
//	register_value.whole_reg = 0x031BD011;
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delay100us(8);		//delay 800us
//        
//	//write R3, turn on TX/RX clocks
//	register_value.whole_reg = 0x29915CD3;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//
//	//write R0, turn on PLL
//	register_value.whole_reg = 0x015759A0;
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(40);		//delay 40us
//
//	//write R2, turn on PA
//	register_value.whole_reg = 0x06B6882;			//Ramp Rate = 16 codes/bit, TX level = 2;
////	register_value.whole_reg = 0x006FF582;			//max power TX
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//        
//	register_value.whole_reg = 0x00268614;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//        
//	register_value.whole_reg = 0x00001915;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//        
//	register_value.whole_reg = 0x0504C986;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//        
//	register_value.whole_reg = 0x329668EA;
//	dd_write_7021_reg(&register_value.byte[0]);
  
  
  
	ADF70XX_REG_T register_value;
          //dd_set_ADF7021_ReInitial();
        //write R1, turn on VCO
	register_value.whole_reg = ROM_adf7012_value[1].whole_reg;//0x031B5011;//0x031BD011;      //2013年11月22日修改  天线驱动偏执电流   2.1mA-->1.5mA
	//register_value.whole_reg = 0x031B5091;    //Colck OUT 5.00MHz
	dd_write_7021_reg(&register_value.byte[0]);
	//Delayus(800);		//delay 800us
        for(i=0;i<20;i++)  Delayus(122);   //40us


	
	//write R3, turn on TX/RX clocks
	register_value.whole_reg = 0x29915CD3;//0x2991A0D3;
	dd_write_7021_reg(&register_value.byte[0]);
        Delayus(122);		//delay 40us

	//write R0, turn on PLL
	//register_value.whole_reg = 0x0154DC30;       //CH=426.075MHz
        register_value.whole_reg = 0x01575710;   //CH=429.175MHz
        //register_value.whole_reg = 0x01576140;//CH=429.225MHz
	//register_value.whole_reg = 0x0154DC30;       //CH=426.075MHz
        //if(TX_Freq_CH==1)register_value.whole_reg = 0x0154DC30;       //CH=426.075MHz
//        if(TX_Freq_CH==2)register_value.whole_reg = 0x01575710;   //CH=429.175MHz
//        else if(TX_Freq_CH==4)register_value.whole_reg = 0x01575C30;  //CH=429.200MHz
//        else if(TX_Freq_CH==6)register_value.whole_reg = 0x01576140;//CH=429.225MHz
	dd_write_7021_reg(&register_value.byte[0]);
	Delayus(122);		//delay 40us

	//write R2, turn on PA
	register_value.whole_reg = 0x00566882;//0x00536882;//0x006B6882;	//2013年11月22日修改	TX频偏 1.6K 2FSK  功率:51（10dBM） （0x00566882）
        //register_value.whole_reg = 0x006E6882;                     //2013年11月29日修改  TX频偏 2K 2FSK  功率:51（10dBM）       （0x006E6882）
	dd_write_7021_reg(&register_value.byte[0]);
        Delayus(122);		//delay 40us

	register_value.whole_reg = 0x00289A14;//0x00268614;       //2013年11月22日修改  频偏 1.6K 2FSK correlator（0x00289A14）-->2K 2FSK correlator（0x00268614）
        //register_value.whole_reg = 0x00200004;                    //2013年11月29日修改   2FSK linear（0x00200004）   频偏不设置
	dd_write_7021_reg(&register_value.byte[0]);
        Delayus(122);		//delay 40us

//	register_value.whole_reg = 0x00001915;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//
//	register_value.whole_reg = 0x0504C986;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//
//	register_value.whole_reg = 0x329668EA;
//	dd_write_7021_reg(&register_value.byte[0]);  
	
	register_value.whole_reg = 0x0000010F;                      //TX test
	dd_write_7021_reg(&register_value.byte[0]);
        Delayus(122);		//delay 40us
}


void dd_set_TX_mode_1010pattern(void)
{
  UINT16 i;
//	ADF70XX_REG_T register_value;
//        //write R1, turn on VCO
//	register_value.whole_reg = 0x031BD011;
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delay100us(8);		//delay 800us
//        
//	//write R3, turn on TX/RX clocks
//	register_value.whole_reg = 0x29915CD3;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//
//	//write R0, turn on PLL
//	register_value.whole_reg = 0x015759A0;
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(40);		//delay 40us
//
//	//write R2, turn on PA
//	register_value.whole_reg = 0x06B6882;			//Ramp Rate = 16 codes/bit, TX level = 2;
////	register_value.whole_reg = 0x006FF582;			//max power TX
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//        
//	register_value.whole_reg = 0x00268614;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//        
//	register_value.whole_reg = 0x00001915;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//        
//	register_value.whole_reg = 0x0504C986;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//        
//	register_value.whole_reg = 0x329668EA;
//	dd_write_7021_reg(&register_value.byte[0]);
  
  
  
	ADF70XX_REG_T register_value;
          //dd_set_ADF7021_ReInitial();
        //write R1, turn on VCO
	register_value.whole_reg = ROM_adf7012_value[1].whole_reg;//0x031B5011;//0x031BD011;      //2013年11月22日修改  天线驱动偏执电流   2.1mA-->1.5mA
	//register_value.whole_reg = 0x031B5091;    //Colck OUT 5.00MHz
	dd_write_7021_reg(&register_value.byte[0]);
	//Delayus(800);		//delay 800us
        for(i=0;i<20;i++)  Delayus(122);   //40us


	
	//write R3, turn on TX/RX clocks
	register_value.whole_reg = 0x29915CD3;//0x2991A0D3;
	dd_write_7021_reg(&register_value.byte[0]);
        Delayus(122);		//delay 40us

	//write R0, turn on PLL
	//register_value.whole_reg = 0x0154DC30;       //CH=426.075MHz
        register_value.whole_reg = 0x01575710;   //CH=429.175MHz
        //register_value.whole_reg = 0x01576140;//CH=429.225MHz
	//register_value.whole_reg = 0x0154DC30;       //CH=426.075MHz
        //if(TX_Freq_CH==1)register_value.whole_reg = 0x0154DC30;       //CH=426.075MHz
//        if(TX_Freq_CH==2)register_value.whole_reg = 0x01575710;   //CH=429.175MHz
//        else if(TX_Freq_CH==4)register_value.whole_reg = 0x01575C30;  //CH=429.200MHz
//        else if(TX_Freq_CH==6)register_value.whole_reg = 0x01576140;//CH=429.225MHz
	dd_write_7021_reg(&register_value.byte[0]);
	Delayus(122);		//delay 40us

	//write R2, turn on PA
	register_value.whole_reg = 0x00566882;//0x00536882;//0x006B6882;	//2013年11月22日修改	TX频偏 1.6K 2FSK  功率:51（10dBM） （0x00566882）
        //register_value.whole_reg = 0x006E6882;                     //2013年11月29日修改  TX频偏 2K 2FSK  功率:51（10dBM）       （0x006E6882）
	dd_write_7021_reg(&register_value.byte[0]);
        Delayus(122);		//delay 40us

	register_value.whole_reg = 0x00289A14;//0x00268614;       //2013年11月22日修改  频偏 1.6K 2FSK correlator（0x00289A14）-->2K 2FSK correlator（0x00268614）
        //register_value.whole_reg = 0x00200004;                    //2013年11月29日修改   2FSK linear（0x00200004）   频偏不设置
	dd_write_7021_reg(&register_value.byte[0]);
        Delayus(122);		//delay 40us

//	register_value.whole_reg = 0x00001915;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//
//	register_value.whole_reg = 0x0504C986;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(40);		//delay 40us
//
//	register_value.whole_reg = 0x329668EA;
//	dd_write_7021_reg(&register_value.byte[0]);  
	
	register_value.whole_reg = 0x0000040F;                      //TX test
	dd_write_7021_reg(&register_value.byte[0]);
        Delayus(122);		//delay 40us
}

//void dd_set_RX_mode(void)
//{
//  
//	ADF70XX_REG_T register_value;
//          //dd_set_ADF7021_ReInitial();
//
//	//	for ADF7021DB2 864M
//
//	//write R1, turn on VCO
//	register_value.whole_reg = ROM_adf7012_value[1].whole_reg;//0x031B5011;//0x031BD011;      //2013年11月22日修改  天线驱动偏执电流   2.1mA-->1.5mA
//	dd_write_7021_reg(&register_value.byte[0]);
//        
//        register_value.whole_reg =0x00500882; //0x00680882;        //2013年11月22日修改  TX频偏 1.6K（0x00500882）-->2K（0x00680882）-->3.2K（0x00A80882）-->4K（0x00D00882）
//        //register_value.whole_reg =0x00680882; //0x00680882;        //2013年11月29日修改  TX频偏 1.6K（0x00500882）-->2K（0x00680882）
//	dd_write_7021_reg(&register_value.byte[0]);        
//
//	//write R3, turn on TX/RX clocks
//	register_value.whole_reg = 0x29915CD3;     //1.6K（0x29915CD3）-->2K（0x29915CD3）-->3.2K（0x29920893）-->4K（0x29920893）
//	dd_write_7021_reg(&register_value.byte[0]);
//
//	//write R6 here, if fine IF filter cal is wanted
//
//
////	//write R5 to start IF filter cal
////	register_value.whole_reg = 0x00001915;	//write R5 to start IF filter cal
////	dd_write_7021_reg(&register_value.byte[0]);
////	Delay100us(2);		//delay 0.2ms
////        
////	register_value.whole_reg = 0x0504C986;
////	dd_write_7021_reg(&register_value.byte[0]);  
////        
////	register_value.whole_reg = 0x000231E9;
////	dd_write_7021_reg(&register_value.byte[0]);
////
////	//write R11, configure sync word detect
////	register_value.whole_reg = 0x329668EA;
////	dd_write_7021_reg(&register_value.byte[0]);
////        
////	register_value.whole_reg = 0x0000003B;
////	dd_write_7021_reg(&register_value.byte[0]);   
////        
////	register_value.whole_reg = 0x0000010C;
////	dd_write_7021_reg(&register_value.byte[0]); 
//
//	//write R0, turn on PLL
//	register_value.whole_reg = 0x0954C7B0;    //CH=426.075MHz
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(122);		//delay 40us
//
//	//write R4, turn on demodulation
//	register_value.whole_reg = 0x00289A14;//0x00268614;       //IF_BW =25K   频偏 1.6K 2FSK correlator（0x00289A14）-->2K（0x00268614）-->3.2K（0x00261094）-->4K（0x0024E294）
//	//register_value.whole_reg = 0x00289A14;//0x00268614;       //2013年11月22日修改  频偏 1.6K 2FSK correlator（0x00289A14）-->2K（0x00268614）-->3.2K（0x00261094）-->4K（0x0024E294）
//        //register_value.whole_reg = 0x00200004;                    //2013年11月29日修改   2FSK linear（0x00200004）  频偏不设置
//	dd_write_7021_reg(&register_value.byte[0]);
//
//
//
//        	//write R10, turn on PLL
//	//register_value.whole_reg = 0x049668EA;   //close AFC
//	register_value.whole_reg = 0x049668FA;
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(122);		//delay 40us  
//}
//


////以下是带宽4K，F_BW =25K
//void dd_set_RX_mode(void)
//{
//	ADF70XX_REG_T register_value;
//
//	//write R1, turn on VCO
//	register_value.whole_reg = ROM_adf7012_value[1].whole_reg;
//	dd_write_7021_reg(&register_value.byte[0]);
//        
//        register_value.whole_reg =0x00D00882;
//	dd_write_7021_reg(&register_value.byte[0]);        
//
//	//write R3, turn on TX/RX clocks
//	register_value.whole_reg = 0x29920893;     
//	dd_write_7021_reg(&register_value.byte[0]);
//
//	//write R0, turn on PLL
//	register_value.whole_reg = 0x0954C7B0;    //CH=426.075MHz
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(122);		//delay 40us
//
//	//write R4, turn on demodulation
//	register_value.whole_reg = 0x8024E294;                 
//	dd_write_7021_reg(&register_value.byte[0]);
//
//       	//write R10, turn on PLL
//	//register_value.whole_reg = 0x049668EA;   //close AFC
//	register_value.whole_reg = 0x049668FA;
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(122);		//delay 40us  
//}
////以下是带宽4K，F_BW =25K
//void dd_set_RX_mode_test(void)
//{  
//	ADF70XX_REG_T register_value;
//
//	//write R1, turn on VCO
//	register_value.whole_reg = ROM_adf7012_value[1].whole_reg;
//	dd_write_7021_reg(&register_value.byte[0]);
//        
//        register_value.whole_reg =0x00D00882;
//	dd_write_7021_reg(&register_value.byte[0]);        
//
//	//write R3, turn on TX/RX clocks
//	register_value.whole_reg = 0x29920893;
//	dd_write_7021_reg(&register_value.byte[0]);
//
//	//write R0, turn on PLL
//	register_value.whole_reg = 0x0954C7B0;    //CH=426.075MHz
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(122);		//delay 40us
//
//	//write R4, turn on demodulation
//	register_value.whole_reg = 0x8024E294;                  
//	dd_write_7021_reg(&register_value.byte[0]);
//
//        	//write R10, turn on PLL
//	register_value.whole_reg = 0x049668EA;   //close AFC
//	//register_value.whole_reg = 0x049668FA;
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(122);		//delay 40us  
//}



//以下是带宽4K，F_BW =12.5K
void dd_set_RX_mode(void)
{
//	ADF70XX_REG_T register_value;
//
//	//write R1, turn on VCO
//	register_value.whole_reg = ROM_adf7012_value[1].whole_reg;
//	dd_write_7021_reg(&register_value.byte[0]);
//        
//        register_value.whole_reg =0x00D00882;
//	dd_write_7021_reg(&register_value.byte[0]);        
//
//	//write R3, turn on TX/RX clocks
//	register_value.whole_reg = 0x29920893;
//	dd_write_7021_reg(&register_value.byte[0]);
//
//	//write R0, turn on PLL
//	register_value.whole_reg = 0x0954C7B0;    //CH=426.075MHz
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(122);		//delay 40us
//
//	//write R4, turn on demodulation
//	//register_value.whole_reg = 0x0024E294;     //F_BW =12.5K
//	register_value.whole_reg = 0x8024E294;    //F_BW =25K
//	dd_write_7021_reg(&register_value.byte[0]);
//
//       	//write R10, turn on PLL
//	//register_value.whole_reg = 0x049668EA;   //close AFC
//	register_value.whole_reg = 0x049668FA;
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(122);		//delay 40us  
  
 
  

  
        ADF70XX_REG_T register_value;
	//write R1, turn on VCO
	register_value.whole_reg = 0x031B5011; 
	dd_write_7021_reg(&register_value.byte[0]);
        Delayus(122);		//delay 40us

        register_value.whole_reg =0x00800882;  
	dd_write_7021_reg(&register_value.byte[0]);

	//write R3, turn on TX/RX clocks
	register_value.whole_reg = 0x29920893;
	dd_write_7021_reg(&register_value.byte[0]);

//        register_value.whole_reg = 0x00001915;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(300);   //0.2ms

        register_value.whole_reg = 0x0504C996;
	dd_write_7021_reg(&register_value.byte[0]);

	register_value.whole_reg = 0x00001915;
	dd_write_7021_reg(&register_value.byte[0]);
           //5ms
        Delayus(244);		//delay 80us
        Delayus(244);		//delay 80us
        Delayus(244);		//delay 80us
        Delayus(244);		//delay 80us
        Delayus(244);		//delay 80us
        Delayus(244);		//delay 80us
        
//        	//write R12
//        register_value.whole_reg = 0x0000003C;
//	dd_write_7021_reg(&register_value.byte[0]);   
//        Delayus(122);		//delay 40us
        
        register_value.whole_reg = 0x0954C7B0;//0x0954C7B0; //CH=426.075MHz
        dd_write_7021_reg(&register_value.byte[0]);
        Delayus(122);		//delay 40us
        	//write R4, turn on demodulation
        register_value.whole_reg = 0x00280294;
	dd_write_7021_reg(&register_value.byte[0]);
        Delayus(122);		//delay 40us
        
//        	//write R9
//        register_value.whole_reg = 0x000231E9;//0x000231E9;  //0x005631E9;
//	dd_write_7021_reg(&register_value.byte[0]);   
//        Delayus(122);		//delay 40us

	//write R10, turn on PLL
	register_value.whole_reg = 0x029668FA;
	dd_write_7021_reg(&register_value.byte[0]);
	Delayus(122);		//delay 40us 
}

void dd_set_ADF7021_Freq(void)
{
      ADF70XX_REG_T register_value;
      
      register_value.whole_reg = 0x0954C7B0;//0x0954C7B0;
      dd_write_7021_reg(&register_value.byte[0]);
      Delayus(122);		//delay 40us 
      
      register_value.whole_reg = 0x029668FA;
      dd_write_7021_reg(&register_value.byte[0]);
      Delayus(122);		//delay 40us 
}

//以下是带宽4K，F_BW =12.5K
void dd_set_RX_mode_test(void)
{  
//	ADF70XX_REG_T register_value;
//
//	//write R1, turn on VCO
//	register_value.whole_reg = ROM_adf7012_value[1].whole_reg;
//	dd_write_7021_reg(&register_value.byte[0]);
//        
//        register_value.whole_reg =0x00D00882;
//	dd_write_7021_reg(&register_value.byte[0]);        
//
//	//write R3, turn on TX/RX clocks
//	register_value.whole_reg = 0x29920893;
//	dd_write_7021_reg(&register_value.byte[0]);
//
//	//write R0, turn on PLL
//	register_value.whole_reg = 0x0954C7B0;    //CH=426.075MHz
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(122);		//delay 40us
//
//	//write R4, turn on demodulation
//	//register_value.whole_reg = 0x0024E294;     //F_BW =12.5K
//	register_value.whole_reg = 0x8024E294;    //F_BW =25K
//	dd_write_7021_reg(&register_value.byte[0]);
//
//        	//write R10, turn on PLL
//	register_value.whole_reg = 0x049668EA;   //close AFC
//	//register_value.whole_reg = 0x049668FA;
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(122);		//delay 40us  
//	
////        	//write R9  AGC
////	register_value.whole_reg = 0x01A231E9;   //
////	dd_write_7021_reg(&register_value.byte[0]);
////	Delayus(122);		//delay 40us 	
  
  
        ADF70XX_REG_T register_value;
	//write R1, turn on VCO
	register_value.whole_reg = 0x031B5011; 
	dd_write_7021_reg(&register_value.byte[0]);
        Delayus(122);		//delay 40us

        register_value.whole_reg =0x00800882;  
	dd_write_7021_reg(&register_value.byte[0]);

	//write R3, turn on TX/RX clocks
	register_value.whole_reg = 0x29920893;
	dd_write_7021_reg(&register_value.byte[0]);

//        register_value.whole_reg = 0x00001915;
//	dd_write_7021_reg(&register_value.byte[0]);
//        Delayus(300);   //0.2ms

        register_value.whole_reg = 0x0504C996;
	dd_write_7021_reg(&register_value.byte[0]);

	register_value.whole_reg = 0x00001915;
	dd_write_7021_reg(&register_value.byte[0]);
           //5ms
        Delayus(244);		//delay 80us
        Delayus(244);		//delay 80us
        Delayus(244);		//delay 80us
        Delayus(244);		//delay 80us
        Delayus(244);		//delay 80us
        Delayus(244);		//delay 80us
        
        register_value.whole_reg = 0x0954C7B0; //CH=426.075MHz
        dd_write_7021_reg(&register_value.byte[0]);
        Delayus(122);		//delay 40us
        	//write R4, turn on demodulation
        register_value.whole_reg = 0x00280294;
	dd_write_7021_reg(&register_value.byte[0]);
        
	//write R10, turn on PLL
	register_value.whole_reg = 0x029668EA;
	dd_write_7021_reg(&register_value.byte[0]);
	Delayus(122);		//delay 40us   
}


////以下是带宽2.5K，F_BW =12.5K
//void dd_set_RX_mode(void)
//{
//	ADF70XX_REG_T register_value;
//
//	//write R1, turn on VCO
//	register_value.whole_reg = ROM_adf7012_value[1].whole_reg;
//	dd_write_7021_reg(&register_value.byte[0]);
//        
//        register_value.whole_reg =0x00800882;
//	dd_write_7021_reg(&register_value.byte[0]);        
//
//	//write R3, turn on TX/RX clocks
//	register_value.whole_reg = 0x29920893;
//	dd_write_7021_reg(&register_value.byte[0]);
//
//	//write R0, turn on PLL
//	register_value.whole_reg = 0x0954C7B0;    //CH=426.075MHz
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(122);		//delay 40us
//
//	//write R4, turn on demodulation
//	register_value.whole_reg = 0x00280294;                  
//	dd_write_7021_reg(&register_value.byte[0]);
//
//       	//write R10, turn on PLL
//	//register_value.whole_reg = 0x049668EA;   //close AFC
//	register_value.whole_reg = 0x049668FA;
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(122);		//delay 40us  
//}
////以下是带宽2.5K，F_BW =12.5K
//void dd_set_RX_mode_test(void)
//{  
//	ADF70XX_REG_T register_value;
//
//	//write R1, turn on VCO
//	register_value.whole_reg = ROM_adf7012_value[1].whole_reg;
//	dd_write_7021_reg(&register_value.byte[0]);
//        
//        register_value.whole_reg =0x00800882;
//	dd_write_7021_reg(&register_value.byte[0]);        
//
//	//write R3, turn on TX/RX clocks
//	register_value.whole_reg = 0x29920893;
//	dd_write_7021_reg(&register_value.byte[0]);
//
//	//write R0, turn on PLL
//	register_value.whole_reg = 0x0954C7B0;    //CH=426.075MHz
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(122);		//delay 40us
//
//	//write R4, turn on demodulation
//	register_value.whole_reg = 0x00280294;                  
//	dd_write_7021_reg(&register_value.byte[0]);
//
//        	//write R10, turn on PLL
//	register_value.whole_reg = 0x049668EA;   //close AFC
//	//register_value.whole_reg = 0x049668FA;
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(122);		//delay 40us  
//}


////以下是带宽3K，F_BW =12.5K
//void dd_set_RX_mode(void)
//{
//	ADF70XX_REG_T register_value;
//
//	//write R1, turn on VCO
//	register_value.whole_reg = ROM_adf7012_value[1].whole_reg;
//	dd_write_7021_reg(&register_value.byte[0]);
//        
//        register_value.whole_reg =0x00A00882;
//	dd_write_7021_reg(&register_value.byte[0]);        
//
//	//write R3, turn on TX/RX clocks
//	register_value.whole_reg = 0x29920893;
//	dd_write_7021_reg(&register_value.byte[0]);
//
//	//write R0, turn on PLL
//	register_value.whole_reg = 0x0954C7B0;    //CH=426.075MHz
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(122);		//delay 40us
//
//	//write R4, turn on demodulation
//	register_value.whole_reg = 0x00267294;                  
//	dd_write_7021_reg(&register_value.byte[0]);
//
//       	//write R10, turn on PLL
//	//register_value.whole_reg = 0x049668EA;   //close AFC
//	register_value.whole_reg = 0x049668FA;
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(122);		//delay 40us  
//}
////以下是带宽3K，F_BW =12.5K
//void dd_set_RX_mode_test(void)
//{  
//	ADF70XX_REG_T register_value;
//
//	//write R1, turn on VCO
//	register_value.whole_reg = ROM_adf7012_value[1].whole_reg;
//	dd_write_7021_reg(&register_value.byte[0]);
//        
//        register_value.whole_reg =0x00A00882;
//	dd_write_7021_reg(&register_value.byte[0]);        
//
//	//write R3, turn on TX/RX clocks
//	register_value.whole_reg = 0x29920893;
//	dd_write_7021_reg(&register_value.byte[0]);
//
//	//write R0, turn on PLL
//	register_value.whole_reg = 0x0954C7B0;    //CH=426.075MHz
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(122);		//delay 40us
//
//	//write R4, turn on demodulation
//	register_value.whole_reg = 0x00267294;                  
//	dd_write_7021_reg(&register_value.byte[0]);
//
//        	//write R10, turn on PLL
//	register_value.whole_reg = 0x049668EA;   //close AFC
//	//register_value.whole_reg = 0x049668FA;
//	dd_write_7021_reg(&register_value.byte[0]);
//	Delayus(122);		//delay 40us  
//}

void dd_set_ADF7021_Power_on(void)
{
  UINT8 i;
//	if (ADF7021_CE == 0)
//	{
//		ADF7021_CE = 1;
//		//phy_state = PHY_POWERON;
//		//if ( is_use_crystal == TRUE ) 	dd_short_delay(25);	
//               //     Delayus(1000);             //delay 1ms
//	      for(i=0;i<12;i++)
//                Delayus(250);             //delay 80us
//
//	}
  
  
              ADF7021_CE=0;
	      for(i=0;i<12;i++)
                Delayus(250);             //delay 80us 
              ADF7021_CE=1;
	      for(i=0;i<12;i++)
                Delayus(250);             //delay 80us               
}

//const unsigned char gain_correction[] = 
//    { 2*86, 0, 0, 0, 2*58, 2*38, 2*24, 0, 
//	0, 0, 0, 0, 0, 0, 0, 0 }; // 7021

//const unsigned char gain_correction[] = 
//    { 2*86, 2*78, 2*68, 2*52, 2*58, 2*38, 2*24, 0, 
//	0, 0, 0, 0, 0, 0, 0, 0 }; // 7021
//
//void dd_read_RSSI(void)
//{
//	ADF70XX_REG_T RSSI_value;
//        UINT16 num,num1;
//
//	RSSI_value = dd_read_7021_reg(0x14);    
//        RSSI_value_buf= RSSI_value;    
//    
//    num=(RSSI_value.byte[2]*256+RSSI_value.byte[3])*2;
//    num1=(num & 0x0F00)>>8;
//    num = num & 0x00FF;
//	num += gain_correction[num1] ;
//    rssi = num /4;
//	//RSSI(dBm) = rssi + 130    
//
//}




const unsigned char gain_correction[] = 
    { 2*111, 2*78, 2*88, 2*52, 2*58, 2*24, 2*24, 0, 
	0, 0, 0, 0, 0, 0, 0, 0 }; // 7021

void dd_read_RSSI(void)
{
	ADF70XX_REG_T RSSI_value;
        UINT8 value_x0;

	RSSI_value = dd_read_7021_reg(0x14);    
        RSSI_value_buf= RSSI_value;
        value_x0=RSSI_value.byte[3]&0x7F;  //
        
	RSSI_value.whole_reg += RSSI_value.whole_reg ;

    rssi = RSSI_value.byte[3];
        if((value_x0>65)&&(RSSI_value.byte[2]==2))
           rssi += 14 ;  //2*7
        else rssi += gain_correction[RSSI_value.byte[2] & 0x0F] ;
    rssi = rssi /4 ;
	//RSSI(dBm) = rssi + 130

}

void READ_RSSI_avg(void)
{
                   if(ADF7021_MUXOUT==1)
                   {
                        dd_read_RSSI(); 
                        RAM_rssi_CNT++;
                        RAM_rssi_SUM +=rssi;
                        if(RAM_rssi_CNT>=20){   //200
                          RAM_rssi_AVG=RAM_rssi_SUM/RAM_rssi_CNT;
                          RAM_rssi_CNT=0;
                          RAM_rssi_SUM=0;
                        }  
                   }  
}