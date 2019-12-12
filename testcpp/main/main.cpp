/* CPP Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
// #include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"

#define PRIORITY1 1 // highest can be configMAX_PRIORITIES –1 (FreeRTOSConfig.hheader file)
#define PRIORITY2 0 // lowest

EventGroupHandle_t handle;

#define ATM_AVAILABLE BIT0
#define LOW_ON_CASH BIT1

BaseType_t b;
void task_get_cash(void *params)
{
    for(;;)
    {
        printf("\t\tWaiting...\n");        
        xEventGroupWaitBits(handle,ATM_AVAILABLE|LOW_ON_CASH,pdTRUE,pdTRUE,7000 / portTICK_PERIOD_MS);
        printf("\t0\tGot cash!\n");        
    }        
}
void task_low_on_cash(void *params)
{
    for(;;)
    {
        printf("\t1\tLow on cash...\n");
        xEventGroupSetBits(handle,LOW_ON_CASH);
        vTaskDelay(7700 / portTICK_PERIOD_MS);
    }        
}
void task_ATM_new_day(void *params)
{
    for(;;)
    {
        printf("1\t\tNew day! You can only withdraw once per day...\n");
        xEventGroupSetBits(handle,ATM_AVAILABLE);
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }        
}
extern "C" {
    void app_main(void);
}

void app_main(void)
{
    handle = xEventGroupCreate();
    xTaskCreate(task_ATM_new_day, "task 1", 1024, NULL, 1, NULL);
    xTaskCreate(task_low_on_cash, "task 2", 1024, NULL, 1, NULL); 
    xTaskCreate(task_get_cash, "task 3", 1024, NULL, 2, NULL); 
}