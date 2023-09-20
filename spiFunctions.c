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
#include "bioZ.h"


 


/***** Definitions *****/
#define SPI_SPEED 1000000// Bit Rate

// Board Selection
#define SPI MXC_SPI1
#define SPI_IRQ SPI1_IRQn
#define FTHR_Defined 1


extern uint8_t gReadBuf[100];
extern uint8_t gHold[100];
mxc_spi_pins_t spi_pins;
mxc_spi_req_t req;
int count;
extern int errCnt;


int initSPI(){
/*
Function to start SPI communication - called at start of main

*/
    int retVal;


    
    spi_pins.clock = TRUE;
    spi_pins.miso = TRUE;
    spi_pins.mosi = TRUE;
    spi_pins.sdio2 = FALSE;
    spi_pins.sdio3 = FALSE;
    spi_pins.ss0 = TRUE;
    spi_pins.ss1 = FALSE;
    spi_pins.ss2 = FALSE;
    


	retVal = MXC_SPI_Init(SPI, 1, 0, 1, 0, SPI_SPEED, spi_pins);//initialise SPI

        if (retVal != E_NO_ERROR) {
            printf("\nSPI INITIALIZATION ERROR\n");
            return retVal;
        }



      
    retVal = MXC_SPI_SetMode(SPI, 0); // ** SPI modes different in SDK

     if (retVal != E_NO_ERROR) {
            printf("\nMODE ERROR\n");
            return retVal;
        }
    



    retVal = MXC_SPI_SetDataSize(SPI, 8);//num of bits per character, 8 as byte

        if (retVal != E_NO_ERROR) {
            printf("\nSPI SET DATASIZE ERROR: %d\n", retVal);
            return retVal;
        }

    retVal = MXC_SPI_SetWidth(SPI, SPI_WIDTH_STANDARD);

        if (retVal != E_NO_ERROR) {
            printf("\nSPI SET WIDTH ERROR: %d\n", retVal);
            return retVal;
        }






    return E_NO_ERROR;



}






uint8_t doSPI(uint8_t *tx_buf, uint8_t tx_len, uint8_t *rx_buf, uint8_t rx_len)
{ 
    /*
    This is a function to perform simple SPI transactions
    It is called within regRead or regWrite

    tx_buf and rx_buf are the arrays for the transmit and receive data
    and tx_len and rx_len are the lengths of the data
    
    
    */
        MXC_Delay(MXC_DELAY_MSEC(10));

        
        int err;

        req.spi = SPI;
        req.txData = (uint8_t *)tx_buf; //buffer with transmit data
        req.rxData = rx_buf; //buffer for received data
        req.txLen = tx_len; //num of bytes to be sent
        req.rxLen = rx_len; // num of bytes to receive (from regread/write)
        req.ssIdx = 0; //slave select line to use 
        req.ssDeassert = 1; // ? deassert ss at end of transaction
        req.txCnt = 0; //num ac transmitted
        req.rxCnt = 0; //num stored
        req.completeCB = NULL;

        err = MXC_SPI_MasterTransaction(&req);
         
    
        if (err != E_NO_ERROR) {
            printf("\nSPI TRANSACTION FAIL: %d\n", err);
            return err;
             }

        int i=0;
        for(i=0;i<rx_len;i++){
             gReadBuf[i]=rx_buf[i];
        }

 
       
       
      return err;


 }

        




void sleep(uint32_t ms)
{

	
}

void regWrite(uint8_t regAddr, uint8_t val)
{   
    /*
    Function to write to register
    */
	uint8_t ix=0, tx_len=3, tx_buf[tx_len];
	tx_buf[ix++] = regAddr;
	
	
		tx_buf[ix++] = 0x00;
		tx_buf[ix++] = val;
		int x = doSPI(tx_buf, tx_len, NULL, 0);

        if(x!=0)
        printf("ERROR %X \n",x);



}

int regRead(uint8_t regAddr)
{   
    /*

    Function to read from register

 
    
    */
    
        uint8_t ix=0, tx_len=3;
        uint8_t tx_buf[tx_len],rx_buf[tx_len];
        int i=0;
        tx_buf[ix++] = regAddr;
        tx_buf[ix++] = 0x80;
        tx_buf[ix]=0x0;
  
        for(i=0;i<tx_len;i++){
            rx_buf[i]=0x0;
                }

		


        int err;
        
        err = doSPI(tx_buf, tx_len, rx_buf, tx_len);
        if(err==0){


        return gReadBuf[2];
        }
        else
        return err;

}


int shutdownSPI(){
    /*
    
    End SPI communication at end of transactions
    
    */
        int retVal=0;
        retVal = MXC_SPI_Shutdown(SPI);

        if (retVal != E_NO_ERROR) {
            printf("\n-->SPI SHUTDOWN ERROR: %d\n", retVal);
            return retVal;
        }

        else{
        printf("SPI shutdown \n");
        return E_NO_ERROR;
        }
}

void changeReg(uint8_t regAddr, uint8_t val,uint8_t bit1, uint8_t numBits){
    /*
    This is a function to change specific bits of the byte
    */

   int i=0;
   uint8_t x1=0;
    for(i=7;i>bit1;i--){
        x1 = x1+pow(2,i);
    }
   
    uint8_t x2=0;
    for(i=0;i<(bit1-numBits+1);i++){
        
        x2 = x2+(pow(2,i));
 
    }

    uint8_t newBits = x1+x2;
    uint8_t reg1 = regRead(regAddr);
    newBits = reg1&newBits;
    val = val << (bit1 - numBits+1);
    newBits = newBits+val;
    regWrite(regAddr,newBits);



}






int spiBurst(){
    /*
    
    This is a function to perform an SPI burst on the FIFO address 0x0C
    
    
    */
    errCnt =0;
    uint8_t regAddr= 0x0C;
    uint16_t  fifoCount=10;
    int err=0;
    count =0;

    while((err==0)){

        //find number of values stored in FIFO
        regRead(0x0A);
        fifoCount = (gReadBuf[2]&0x7F);
        fifoCount = fifoCount <<1;
        regRead(0x0B);
        fifoCount = gReadBuf[2]+fifoCount;


    
        if(fifoCount>6){ //confirm there are enough values stored
            uint8_t ix=0, tx_len=fifoCount, tx_buf[tx_len],rx_len = fifoCount;
            int i=0;
            tx_buf[ix++] = regAddr;
            tx_buf[ix++] = 0x80;
            
            uint8_t rx_buf[rx_len];
            
            for(i=0;i<tx_len;i++)
                rx_buf[i]=0;


            MXC_Delay(MXC_DELAY_MSEC(10));

            
            

            req.spi = SPI;
            req.txData = (uint8_t *)tx_buf; //buffer with transmit data
            req.rxData = rx_buf; //buffer for received data
            req.txLen = fifoCount; //num of bytes to be sent
            req.rxLen = fifoCount; // num of bytes to receive (from regread/write)
            req.ssIdx = 0; //slave select line to use 
            req.ssDeassert = 1; // ? deassert ss at end of transaction
            req.txCnt = 0; //num ac transmitted
            req.rxCnt = 0; //num stored
            req.completeCB = NULL;

            err = MXC_SPI_MasterTransaction(&req);
            
        
            if (err != E_NO_ERROR) 
            {
                printf("\nSPI TRANSACTION FAIL: %d\n", err);
                return err;
            }


            for(i=0;i<fifoCount;i++){
                if(rx_buf[i]!=0){
                    gHold[0]=rx_buf[i];
                    gHold[1]=rx_buf[i+1];
                    gHold[2]=rx_buf[i+2];

                    i=i+3;

                    while(rx_buf[i]==0)
                        i++;

                    gHold[3]=rx_buf[i];
                    gHold[4]=rx_buf[i+1];
                    gHold[5]=rx_buf[i+2];

                    i=i+2;


                    calcBioZ(gHold);

                }


            }


        }
    
    }




return err;


}