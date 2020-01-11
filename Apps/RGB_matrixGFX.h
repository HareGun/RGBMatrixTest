#ifndef __RGB_MATRIX_GFX_H
#define __RGB_MATRIX_GFX_H

#include <stdio.h>
#include <stdint.h>
#include "SK6812_drv.h"




typedef SK6812_pixel_t       RGB_pixel_t;

typedef void sendMatrix_func_t(SK6812_pixel_t *p_displayBuff, uint32_t buff_len);

typedef struct
{
  RGB_pixel_t *p_displayBuff;
  uint32_t buffSize;
  uint16_t width;
  uint16_t height;
  sendMatrix_func_t *p_sendFunc;
} RGB_MatrixGFX_Handle_t;

void RGB_MatrixGFX_Init(void);

extern void RGB_MatrixGFX_drawPixel(RGB_MatrixGFX_Handle_t *handle, uint8_t x, uint8_t y, 
                                    RGB_pixel_t color);

extern void RGB_MatrixGFX_drawRGBmap(RGB_MatrixGFX_Handle_t *handle, uint8_t x, uint8_t y, 
                                     const RGB_pixel_t *bitmap, uint8_t w, uint8_t h);

extern void RGB_MatrixGFX_fillRect(RGB_MatrixGFX_Handle_t *handle, uint8_t x, uint8_t y, 
                                   uint8_t w, uint8_t h, RGB_pixel_t color);

extern void RGB_MatrixGFX_drawChar5x7(RGB_MatrixGFX_Handle_t *handle, uint8_t x, uint8_t y, 
                                      uint8_t c, RGB_pixel_t color);

extern void oled_drawstring(RGB_MatrixGFX_Handle_t *handle, uint8_t x, uint8_t y, 
                            char *c, RGB_pixel_t color);

extern void RGB_MatrixGFX_drawBitmap(RGB_MatrixGFX_Handle_t *handle, uint8_t x, uint8_t y, 
                                     uint8_t w, uint8_t h, const uint8_t *bitmap, RGB_pixel_t color);

extern void RGB_MatrixGFX_update(RGB_MatrixGFX_Handle_t *handle);
extern void RGB_MatrixGFX_clean(RGB_MatrixGFX_Handle_t *handle);

#endif /* __RGB_MATRIX_GFX_H */
