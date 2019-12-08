#include <stdio.h>
#include <stdlib.h>

#include "cli_task.h"
#include "cmd_parser.h"

#include "FreeRTOS.h"
#include "task.h"

void task(void *arg){
	char *s = arg;
	while(1){
		printf("%s\n",s);
		vTaskDelay(pdMS_TO_TICKS(500));
	}
}


int main(void)
{
    // createCliTask();
    // createCmdParserTask();
	xTaskCreate(task, "task1", 32, "task1", 3, NULL);
	xTaskCreate(task, "task2", 32, "task2", 5, NULL);
    vTaskStartScheduler();
    return 0;
}

/********************************************************/
/* This is a stub function for FreeRTOS_Kernel */
void vMainQueueSendPassed( void )
{
    return;
}

/* This is a stub function for FreeRTOS_Kernel */
void vApplicationIdleHook( void )
{
    return;
}

