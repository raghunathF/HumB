/*
 * LED_control.c
 *
 * Created: 12/8/2017 10:10:34 AM
 *  Author: raghu
 */ 
#include <asf.h>
#include "LED.h"
#include "LED_control.h"

void update_LEDS(uint8_t led1, uint8_t led2, uint8_t led3)
{
	temp_compare_led_array[0] = led1;//Led1
	temp_compare_led_array[1] = led2;//led2
	temp_compare_led_array[2] = led3;//Led3
	initializing_LED_pin_array();
	increasing_LED_sort_tag();
	LED_transfer_temp();
	update_compare_led_array = true;
}
