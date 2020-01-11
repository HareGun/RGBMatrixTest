#ifndef __MATRIX_APP_H
#define __MATRIX_APP_H

#include <stdio.h>
#include <stdint.h>
#include "RGB_MatrixGFX.h"

#define RGB_MATRIX_WIDTH       (72u)
#define RGB_MATRIX_HEIGHT      (7u)

#define RGB_MATRIX_BUFF_SIZE   (RGB_MATRIX_WIDTH * RGB_MATRIX_HEIGHT)


void RGB_Matrix_Init(void);

void RGB_Matrix_loop(void);



#endif /* __MATRIX_APP_H */
