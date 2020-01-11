#ifndef __SL6812_DRV_H
#define __SL6812_DRV_H

#include <stdio.h>
#include <stdint.h>
#include "stm32f10x.h"
#include "delay.h"

#define SPI_TX_DMA_CHANNEL		DMA1_Channel5
//#define SPI_TX_DMA_IRQn			DMA1_Channel5_IRQn

#define SPI_BYTE_LEN_PER_PIXEL			3

typedef struct 
{
  uint8_t g;
  uint8_t r;
  uint8_t b;
} SK6812_pixel_t;




void SK6812_drvInit(void);

void SK6812_sendBuff1(SK6812_pixel_t *p_displayBuff, uint32_t buff_len);
void SK6812_sendBuff2(SK6812_pixel_t *p_displayBuff, uint32_t buff_len);


#endif /* __SL6812_DRV_H */
