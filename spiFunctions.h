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

void changeReg(uint8_t regAddr, uint8_t val,uint8_t bit1, uint8_t numBits);
int initSPI();
void regWrite(uint8_t regAddr, uint8_t val);
int regRead(uint8_t regAddr);
int shutdownSPI();
int spiBurst();
uint8_t doSPI(uint8_t *tx_buf, uint8_t tx_len, uint8_t *rx_buf, uint8_t rx_len);
