#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

TimerHandle_t mytimer;
void *const my_timerid;

void my_timer_callback(TimerHandle_t xTimer)
{
    printf("timer fired\n");
}

void tone_task(void *data)
{
    while(1)
    {
        printf(" task1 started \n");
        //...............//
        printf(" task1 ended \n");
        vTaskDelay(1000/ portTICK_PERIOD_MS);

    }
}

void ttwo_task(void *data)
{
    while(1)
    {
        printf(" task2 started \n");
        //...............//
        printf(" task2 ended \n");
        vTaskDelay(2000/ portTICK_PERIOD_MS);

    }
}

void tthree_task(void *data)
{
    mytimer = xTimerCreate("my_timer", pdMS_TO_TICKS(10000), pdTRUE, my_timerid,my_timer_callback);
    
    xTimerStart(mytimer,0);
    while(1)
    {
        printf(" task3 started \n");
       
        printf(" task3 ended \n");
        vTaskDelay(5000/ portTICK_PERIOD_MS);

    }
}

void app_main(void)
{
    xTaskCreate(tone_task, "tone_tsk", 2048, NULL, 10, NULL);
    xTaskCreate(ttwo_task, "ttwo_tsk", 2048, NULL, 8, NULL);
    xTaskCreate(tthree_task, "tthree_tsk", 2048, NULL, 6, NULL);
  
    
   
}

