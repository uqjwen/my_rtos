#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "cli_task.h"
#include "cmd_parser.h"

#include "FreeRTOS.h"
#include "task.h"

void task(void *arg){
	char *s = arg;
	// while(1){
		printf("%s, threadID:%d\n",s, pthread_self());
		vTaskDelay(pdMS_TO_TICKS(500));
	// }
}


int main(void)
{
    // createCliTask();
    // createCmdParserTask();
    // printf('INCLUDE_vTaskDelete = %d\n', INCLUDE_vTaskDelete);
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

