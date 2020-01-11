/**
  ******************************************************************************
  * @file    RGB_MatrixGFX.c
  * @author  Hare
  * @version V1.0
  * @date    
  * @brief    
  ******************************************************************************
  */

#include "RGB_MatrixGFX.h"
#include "glcdfont.c"


/**
  * @brief  
  * @param  None
  * @retval None
  */
void RGB_MatrixGFX_Init(void)
{
  
}

void RGB_MatrixGFX_drawPixel(RGB_MatrixGFX_Handle_t *handle, uint8_t x, uint8_t y, 
                             RGB_pixel_t color)
{
  if (NULL == handle || NULL == handle->p_displayBuff)
    return;

  if ((x >= handle->width) || (y >= handle->height))
    return;

  // x is which column
  uint32_t pixel_index = x + (y * handle->width);

  handle->p_displayBuff[pixel_index] = color;
}

void RGB_MatrixGFX_drawRGBmap(RGB_MatrixGFX_Handle_t *handle, uint8_t x, uint8_t y, 
                     const RGB_pixel_t *rgbmap, uint8_t w, uint8_t h) 
{
  if (NULL == handle || NULL == handle->p_displayBuff)
    return;
  if ((x >= handle->width) || (y >= handle->height))
    return;
    
  for (uint8_t j=0; j<h; j++) 
  {
    for (uint8_t i=0; i<w; i++ ) 
    {
      RGB_MatrixGFX_drawPixel(handle, x+i, y+j, rgbmap[i + (j * w)]);
    }
  }
}

void RGB_MatrixGFX_fillRect(RGB_MatrixGFX_Handle_t *handle, uint8_t x, uint8_t y, 
                            uint8_t w, uint8_t h, RGB_pixel_t color)
{
  if (NULL == handle || NULL == handle->p_displayBuff)
    return;
  if ((x >= handle->width) || (y >= handle->height))
    return;
  
	// stupidest version - just pixels - but fast with internal buffer!
	for (uint8_t i=x; i<x+w; i++)
  {
		for (uint8_t j=y; j<y+h; j++) 
    {
      RGB_MatrixGFX_drawPixel(handle, i, j, color);
		}
	}
}

void RGB_MatrixGFX_drawChar5x7(RGB_MatrixGFX_Handle_t *handle, uint8_t x, uint8_t y, 
                             uint8_t c, RGB_pixel_t color)
{
  if ((x >= handle->width) || (y >= handle->height))
    return;
  
  for (uint8_t i =0; i<5; i++) 
  {
     for(uint8_t j =0; j<8; j++)
     {
        if(*(font+(c*5)+i-160) & (1<<j))
        {
          RGB_MatrixGFX_drawPixel(handle, x+i, y+j, color);
        }
     }
   }
}
                             
void oled_drawstring(RGB_MatrixGFX_Handle_t *handle, uint8_t x, uint8_t y, 
                     char *c, RGB_pixel_t color) {
  while (c[0] != 0)
  {
    RGB_MatrixGFX_drawChar5x7(handle, x, y, c[0], color);
    c++;
    x += 6; // 6 pixels wide
    
    if (x+6 >= handle->width)
    {
      x = 0;    // ran out of this line
      y += 7;
    }
    
    if (y >= handle->height)
    {
      return;        // ran out of space :(
    }
      

	 }
  
}
                     

void RGB_MatrixGFX_drawBitmap(RGB_MatrixGFX_Handle_t *handle, uint8_t x, uint8_t y, 
                              uint8_t w, uint8_t h, const uint8_t *bitmap, RGB_pixel_t color)
{
//  if ((x >= handle->width) || (y >= handle->height))
//    return;
  
  for (uint8_t j=0; j<h; j++) 
  {
    for (uint8_t i=0; i<w; i++ ) 
    {
      if (*(bitmap + i + (j/8)*w) & (1<<(j%8))) 
      {
        RGB_MatrixGFX_drawPixel(handle, x+i, y+j, color);
      }
    }
	}
}


void RGB_MatrixGFX_update(RGB_MatrixGFX_Handle_t *handle)
{
  if (NULL == handle ||
      NULL == handle->p_displayBuff ||
      NULL == handle->p_sendFunc)
  {
    return;
  }

  handle->p_sendFunc(handle->p_displayBuff, handle->buffSize);
}


void RGB_MatrixGFX_clean(RGB_MatrixGFX_Handle_t *handle)
{
  if (NULL == handle ||
      NULL == handle->p_displayBuff ||
      NULL == handle->p_sendFunc)
  {
    return;
  }
	memset(handle->p_displayBuff, 0x00, sizeof(RGB_pixel_t[handle->buffSize]));
//  handle->p_sendFunc(handle->p_displayBuff, handle->buffSize);
}

