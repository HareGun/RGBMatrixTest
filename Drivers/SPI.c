/**
  ******************************************************************************
  * @file    SPI.c
  * @author  Hare
  * @version V1.0
  * @date    
  * @brief   USART应用函数接口
  ******************************************************************************
  */
#include "SPI.h"
#include "SK6812_drv.h"
#include "matrix_app.h"
/**
  * @brief      WS2812B SPI总线初始化
  * @param 
  */
void WS2812b_Configuration(void)
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
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
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



