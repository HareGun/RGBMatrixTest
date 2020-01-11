/*

*/

#include "user_common.h"
#include "SystemInit_Tasks.h"
#include "SEGGER_SYSVIEW.h"


RCC_ClocksTypeDef RCC_Clocks;

int main(void){
	
	/* 优先级分组4 （抢占式16）使用os不要分组 */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
  /* SYSTICK初始化 */
  SysTick_Config(SystemCoreClock/1000);
  delay_init();
  
  SEGGER_SYSVIEW_Conf();
  
  //创建系统初始化任务
	xTaskCreate(vTaskSystemInit,   /* 任务函数 */
				"Task SysInit",    /* 任务名 */
				 512,              /* 任务栈大小，单位字 */
				 NULL,             /*  任务形参 */
				 5,                /* 任务优先级，值越大优先级越高 */
				 NULL);  		   /* 任务句柄 */
	
	/* 开始任务调度，成功则不返回 */
	vTaskStartScheduler();
  
  while(1){
  

  }
	
	return 0;
}
