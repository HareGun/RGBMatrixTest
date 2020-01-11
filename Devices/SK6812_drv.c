/**
  ******************************************************************************
  * @file    SK6812_drv.c
  * @author  Hare
  * @version V1.0
  * @date    
  * @brief    
  ******************************************************************************
  */

#include "SK6812_drv.h"

#define CODE0 0x80      //0x80 »ò 0xC0
#define CODE1 0xF8      //0xF8 »ò 0xFC


void SK6812_drvInit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
  SPI_InitTypeDef  SPI_InitStructure;
  
  /* Enable peripheral clocks ------------------------------------------------*/
  /* GPIOA,SPI1 clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_SPI1, ENABLE);
  
  /* Configure SPI1 pins: MOSI -----------------------------------------------*/
  /* Confugure MOSI pins as Alternate Function Push Pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 ;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
  /* SPI1 configuration ------------------------------------------------------*/
  SPI_InitStructure.SPI_Direction = SPI_Direction_1Line_Tx;     		//SPI1-Tx_Only_Master
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;							//IDLE=High
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;    //SPI1CLK = 9MHz
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;								//Default Value
  SPI_Init(SPI1, &SPI_InitStructure);
  
  /* Enable SPI1 CRC calculation */
  SPI_CalculateCRC(SPI1, DISABLE);
  
  /* Enable SPI1 */
  SPI_Cmd(SPI1, ENABLE);
  
  
  
}


/**
  * @brief  Transmits one of 24 bits meassages through the SPIx peripheral.
  * @param  Data: where x can be
  *   - =0   CODE0
  *   - >0  CODE1
  * @retval None
  */
void SK6812_send1Bit_spi(volatile u8 Data)
{
  /* Wait for SPI1 Tx buffer empty */
  while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);
  
  /* Send SPI1 data */
  switch(Data)
  {
    case 0:       SPI_I2S_SendData(SPI1, CODE0);  break;
    default:      SPI_I2S_SendData(SPI1, CODE1);  break;
  }
}

void SK6812_send1Pixel_spi(SK6812_pixel_t pixel)
{
  s16 j;
    for(j=7;j>=0;j--)  SK6812_send1Bit_spi(pixel.g & (1<<j));
    for(j=7;j>=0;j--)  SK6812_send1Bit_spi(pixel.r & (1<<j));
    for(j=7;j>=0;j--)  SK6812_send1Bit_spi(pixel.b & (1<<j));
}


void SK6812_sendBuff1(SK6812_pixel_t *p_displayBuff, uint32_t buff_len)
{
	u32 Counter = 0;
  if (NULL == p_displayBuff || 0 == buff_len)
  {
      return;
  }
	
	for(Counter = 0;Counter<buff_len;Counter++)
	{
			SK6812_send1Pixel_spi(p_displayBuff[Counter]);
	}

  //SK6812_sendBuff opt...

}

void SK6812_sendBuff2(SK6812_pixel_t *p_displayBuff, uint32_t buff_len)
{
  if (NULL == p_displayBuff || 0 == buff_len)
  {
      return;
  }

  //SK6812_sendBuff opt...

}


