/**
  ******************************************************************************
  * @file    matrix_app.c
  * @author  Hare
  * @version V1.0
  * @date    
  * @brief    
  ******************************************************************************
  */

#include "matrix_app.h"

#include "SK6812_drv.h"
#include "RGB_MatrixGFX.h"
#include <stdlib.h>
#include <time.h>

#define ARROW_R_BITMAP_WIDTH    (6u)
#define ARROW_R_BITMAP_HEIGHT   (8u)

#define ARROW_L_BITMAP_WIDTH    (6u)
#define ARROW_L_BITMAP_HEIGHT   (8u)

const RGB_pixel_t color_red = {0, 10, 0};
const RGB_pixel_t color_blue = {0, 0, 10};

static const unsigned char arrowR_bitmap[] = 
{
  // '>', 6x8px
  0x00, 0x22, 0x36, 0x3e, 0x1c, 0x08,
};

static const unsigned char arrowL_bitmap[] = 
{
  // '<', 6x8px
  0x00, 0x08, 0x1c, 0x3e, 0x36, 0x22,
};

RGB_pixel_t RGB_Matrix1_Buff[RGB_MATRIX_BUFF_SIZE];

RGB_MatrixGFX_Handle_t RGB_MatrixGFX_handle1;

/**
  * @brief  
  * @param  None
  * @retval None
  */
void RGB_Matrix_Init(void)
{
  SK6812_drvInit();
  
  //获取随机数seed
	srand(3265154);
  
  RGB_MatrixGFX_handle1.p_displayBuff = RGB_Matrix1_Buff;
  RGB_MatrixGFX_handle1.buffSize = RGB_MATRIX_BUFF_SIZE;
  RGB_MatrixGFX_handle1.width = RGB_MATRIX_WIDTH;
  RGB_MatrixGFX_handle1.height = RGB_MATRIX_HEIGHT;
  RGB_MatrixGFX_handle1.p_sendFunc = SK6812_sendBuff1;
  
  
}


void RGB_Matrix_loop(void)
{
//	static int n = 0;
  static int arrow_x = 0;
  static int arrow_y = 0;
	
	static int counter = 0;
  
  static RGB_pixel_t color = {0, 10, 0};
	
	
	counter++;
	if(counter > 50)
	{
		if(color.r == color_red.r)
		{
			color = color_blue;
		}
		else
		{
			color = color_red;
		}
		
		counter = 0;
		
	}
  
	
  
	
	RGB_MatrixGFX_clean(&RGB_MatrixGFX_handle1);
  
//  RGB_MatrixGFX_fillRect(&RGB_MatrixGFX_handle1, n, 1, 
//                         15, 5, color);
//  oled_drawstring(&RGB_MatrixGFX_handle1, 10, 0, 
//                             "5333", color);
//  
//  RGB_MatrixGFX_drawBitmap(&RGB_MatrixGFX_handle1, arrow_x, arrow_y,
//                           ARROW_L_BITMAP_WIDTH, ARROW_L_BITMAP_HEIGHT,
//                           arrowL_bitmap, color);
  for(int n = 0; n<13; n++)
  {
//		color.b = rand()%10;
//		color.g = rand()%10;
//		color.r = rand()%10;
    RGB_MatrixGFX_drawBitmap(&RGB_MatrixGFX_handle1, arrow_x + n*ARROW_L_BITMAP_WIDTH, arrow_y,
                               ARROW_L_BITMAP_WIDTH, ARROW_L_BITMAP_HEIGHT,
                               arrowL_bitmap, color);

		
  }
	
	arrow_x--;
	if(arrow_x <= -6)
	{
		arrow_x = 0;
	}
  
	
//	RGB_MatrixGFX_fillRect(&RGB_MatrixGFX_handle1, 0, 0, 
//                         RGB_MATRIX_WIDTH, RGB_MATRIX_HEIGHT, color);
	
//	n++;
//	if(n>72)
//	{
//			n= 0;
//	}
	
//	RGB_MatrixGFX_drawPixel(&RGB_MatrixGFX_handle1, 2, 1, color);
  
  RGB_MatrixGFX_update(&RGB_MatrixGFX_handle1);
  
}


