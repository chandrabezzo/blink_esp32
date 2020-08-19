/* Blink Example
   This example code is in the Public Domain (or CC0 licensed, at your option.)
   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

/* Can use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
#define GREEN_LED GPIO_NUM_5
#define RED_LED GPIO_NUM_18

void app_main(void)
{
    /* Configure the IOMUX register for pad BLINK_GPIO (some pads are
       muxed to GPIO on reset already, but some default to other
       functions and need to be switched to GPIO. Consult the
       Technical Reference for a list of pads and their default
       functions.)
    */
    gpio_pad_select_gpio(GREEN_LED);
    gpio_pad_select_gpio(RED_LED);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(GREEN_LED, GPIO_MODE_OUTPUT);
    gpio_set_direction(RED_LED, GPIO_MODE_OUTPUT);
    while(1) {

	printf("Turning off the RED LED\n");
        gpio_set_level(RED_LED, 0);
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	printf("Turning on the GREEN LED\n");
		gpio_set_level(GREEN_LED, 1);
		vTaskDelay(1000 / portTICK_PERIOD_MS);

	printf("Turning on the RED LED\n");
		gpio_set_level(RED_LED, 1);
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	printf("Turning off the GREEN LED\n");
		gpio_set_level(GREEN_LED, 0);
		vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
