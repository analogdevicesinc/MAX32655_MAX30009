#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "MAX30009.h"
#include "MAX32655.h"
#include "mxc_device.h"
#include "led.h"
#include "board.h"
#include "mxc_delay.h"
#include "uart.h"
#include "dma.h"
#include "nvic_table.h"
#include "mxc_pins.h"
#include "spi.h"

#include "spiFunctions.h"




extern uint8_t gReadBuf[100];
uint8_t adcIData[10];
uint8_t adcQData[10];
extern uint8_t IMag;
extern int count;
extern int errCnt;



void GSRsettings(){
    /*
    
    These are the necessary settings to measure GSR 
    
    
    */

    regWrite(0x10,0x00);
    regWrite(0x12,0x04);
    regWrite(0x13,0x00);
    regWrite(0x14,0x00);
    regWrite(0x17,0xF9);
    regWrite(0x18,0x1F);
    regWrite(0x19,0x01);
    regWrite(0x1A,0x20);
    regWrite(0x20,0xFF);
    regWrite(0x21,0x00);
    regWrite(0x22,0x14);
    regWrite(0x23,0x00);
    regWrite(0x24,0xF0);
    regWrite(0x25,0x40);
    regWrite(0x26,0x00);
    regWrite(0x27,0xFF);
    regWrite(0x28,0x02);
    regWrite(0x41,0x06);
    regWrite(0x42,0x01);
    regWrite(0x43,0xA0);
    regWrite(0x50,0x00);
    regWrite(0x51,0x00);
    regWrite(0x58,0x07);
    regWrite(0x80,0x80);
    regWrite(0x81,0x00);
}


void setMdiv(int val){
    /*
    This function is specifically to change the M divider value
    as it spans over two seperate registers
    
    
    */
    uint32_t V = val;
    
    uint8_t a = V>>8;
  
    uint8_t b = V&0xFF;


    changeReg(0x17,a,7,2);//step 3:
    changeReg(0x18,b,7,8);//MDIV


}


void setMode(int mode){

    /*
    
    There are many modes available in the MAX30009 data sheet. This function allows you to set the 
    registers according to each of those modes simply by entering the number of the mode.


    **** not all modes available so far ****
    
    
    */
    //using EX4

    if(mode==0){// from BU advice
        changeReg(0x20,0x3,7,2);// step 1: set BIOZ_DAC_OSR = 256
        changeReg(0x17,0x9,4,4); // step 2: set KDIV to get PLL_CLK in range --512
        setMdiv(532);
        changeReg(0x17,1,5,1); //step4: NDIV to 1, meaning 1024
        changeReg(0x20,0x07,5,3); //step 5: BIOZ_ADC_OSR to 7, meaning 1024


        changeReg(0x25,1,6,1); //dc restore
        changeReg(0x25,0,7,1);//bypass Cext


    }

    if(mode==1){
        changeReg(0x20,0x3,7,2);// step 1: set BIOZ_DAC_OSR = 256
        changeReg(0x17,0xD,3,4); // step 2: set KDIV to get PLL_CLK in range --8192
        changeReg(0x17,0x04,7,2);//step 3:
        changeReg(0x18,0x12,7,8);//MDIV to 511
        changeReg(0x17,1,5,1); //step4: NDIV to 1, meaning 1024
        changeReg(0x20,0x07,5,3); //step 5: BIOZ_ADC_OSR to 7, meaning 1024




    }

    if(mode==2){
        changeReg(0x20,0x3,7,2);// step 1: set BIOZ_DAC_OSR = 256
        changeReg(0x17,0xA,3,4); // step 2: set KDIV to get PLL_CLK in range --1024
        setMdiv(799);//step 3: MDIV to 799
        changeReg(0x17,1,5,1); //step4: NDIV to 1, meaning 1024
        changeReg(0x20,0x04,5,3); //step 5: BIOZ_ADC_OSR to 4, meaning 128

    }

        if(mode==3){
    changeReg(0x20,0x3,7,2);// step 1: set BIOZ_DAC_OSR = 256
    changeReg(0x17,0x6,3,4); // step 2: set KDIV to get PLL_CLK in range -64
    setMdiv(499);
    changeReg(0x17,0x0,5,1); //step4: NDIV to 1, meaning 512
    changeReg(0x20,0x04,5,3); //step 5: BIOZ_ADC_OSR to 4, meaning 128


    }

        if(mode==4){
    changeReg(0x20,0x3,7,2);// step 1: set BIOZ_DAC_OSR = 256
    changeReg(0x17,0x3,3,4); // step 2: set KDIV to get PLL_CLK in range --8
    setMdiv(624);
    changeReg(0x17,1,5,1); //step4: NDIV to 1, meaning 1024
    changeReg(0x20,0x04,5,3); //step 5: BIOZ_ADC_OSR to 4, meaning 128


    }

        if(mode==5){
    changeReg(0x20,0x3,7,2);// step 1: set BIOZ_DAC_OSR = 256
    changeReg(0x17,0x1,3,4); // step 2: set KDIV to get PLL_CLK in range --8
    changeReg(0x17,0x02,7,2);//step 3:
    changeReg(0x18,0x70,7,8);//MDIV to 624
    changeReg(0x17,1,5,1); //step4: NDIV to 1, meaning 1024
    changeReg(0x20,0x04,5,3); //step 5: BIOZ_ADC_OSR to 4, meaning 128


    }

    if(mode==6){
        changeReg(0x20,0x3,7,2);// step 1: set BIOZ_DAC_OSR = 256
        changeReg(0x17,0x0,3,4); // step 2: set KDIV to get PLL_CLK in range --1
        setMdiv(427);//step 3: MDIV to 799
        changeReg(0x17,0,5,1); //step4: NDIV to 0, meaning 512
        changeReg(0x20,0x04,5,3); //step 5: BIOZ_ADC_OSR to 4, meaning 128

    }





    

}






 int calcBioZ(uint8_t buf[]){
    /*
    This function uses the readings from the FIFO register
    
    */
    count++;
        uint8_t x1[3], x2[3];
    int i,err=0;

    for(i=0;i<3;i++){
        x1[i]=buf[i];
        x2[i]=buf[i+3];
    }


    uint8_t a = x1[0]&0xF0;
    uint8_t b = x2[0]&0xF0;

    /***************************************************
    Find which array is Quadrature phase and which is In phase
    ********************************************************/
    if((a==0x10)&&(b==0x20)){
        adcIData[0] = (x1[0]&0x0F);
        adcIData[1] = x1[1];
        adcIData[2] = x1[2];


        adcQData[0] = (x2[0]&0x0F);
        adcQData[1] = x2[1];
        adcQData[2] = x2[2];




    }


    else if((a==0x20)&&(b==(0x10))){
        adcIData[0] = (x2[0]&0x0F);
        adcIData[1] = x2[1];
        adcIData[2] = x2[2];


        adcQData[0] = (x1[0]&0x0F);
        adcQData[1] = x1[1];
        adcQData[2] = x1[2];

    }

    else if(x1[0]==0xFF&&x2[0]==0xFF&&x1[1]==0xFF&&x2[1]==0xFF&&x1[2]==0xFF&&x2[2]==0xFF){
        printf("Invalid Data\n");
        return 1;
    }

    else if(x1[0]==0xFF&&x2[0]==0xFF&&x1[1]==0xFF&&x2[1]==0xFF&&x1[2]==0xFE&&x2[2]==0xFF){
        printf("Marker\n");
        return 2;
    }

    else{

        errCnt++;
        return 3;
    }
    double I,Q,temp;
    uint32_t L,d;
    /*
    Convert to one Hex value
    */
    uint32_t adcI = adcIData[2] + (adcIData[1] <<8) + (adcIData[0]<<16);
    uint32_t adcQ = adcQData[2] + (adcQData[1] <<8) + (adcQData[0]<<16);

    /*
    Convert from 2's complement to decimal
    */
    if(adcI>>19==1){

     L = (adcI&0x7FFFF);
     d = 0x80000;


     I=L;
     temp = d;
     I = I-temp;

     adcI=adcI>>1;
     

    }
    else
    I = adcI;


    if(adcQ>>19==1){

    L = (adcQ&0x7FFFF);
    d = 0x80000;


     Q=L;
     temp = d;
     Q = Q-temp;

     adcQ=adcQ>>1;

    }
    else
    Q = adcQ;



    double mag = sqrt(pow(I,2)+pow(Q,2));


    double current = 905E-9; //this depends on settings

    double p = pow(2,19)*1*(2/3.14)*(current);
    double Z = mag/p;

    double Rdc, Ziso1, Ziso2, Zbody;
    Rdc = 10E6;
    Ziso1 = 5429/2;
    Ziso2 = 5429/2;

    Zbody = 1/((1/Z)-(1/Rdc)) - (Ziso1+Ziso2);


  

   if(count>100){
        
        printf("%f      ",Q);
        printf("%f      ",I);
        printf("%f      ",Z); 
        printf("%f \n",Zbody);
        

   }

   return err;

 }














































