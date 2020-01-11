/**
  ******************************************************************************
  * @file    Control_Task.c
  * @author  Hare
  * @version V1.0
  * @date    
  * @brief   控制任务
  ******************************************************************************
  */
  
  
#include "Control_Task.h"

#include "matrix_app.h"



/* 任务句柄，任务创建之后得到对应值，以后想操作这个任务时都需要通过这个句柄来操作 */
TaskHandle_t xHandleTaskControl = NULL;



/**
  * @brief  控制任务
  * @param  pvParameters 任务被创建时传进来的参数
  * @retval None
  */
void vTaskControl(void *pvParameters)
{
  TickType_t xLastWakeTime;
	
	/* 获取当前的系统时间 */
	//xLastWakeTime = xTaskGetTickCount();
  
  RGB_Matrix_Init();
	
	while(1)
	{
    
    RGB_Matrix_loop();
    
    vTaskDelay(50);
    
		//vTaskDelayUntil(&xLastWakeTime, 10);
	}	
}

