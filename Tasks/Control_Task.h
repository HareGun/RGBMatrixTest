#ifndef __CONTROL_TASK_H
#define __CONTROL_TASK_H

#include "user_common.h"



extern TaskHandle_t xHandleTaskControl;
void vTaskControl(void *pvParameters);


#endif /* __CONTROL_TASK_H */
