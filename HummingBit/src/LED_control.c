/*
 * LED_control.c
 *
 * Created: 12/8/2017 10:10:34 AM
 *  Author: raghu
 */ 
#include <asf.h>
#include "LED.h"
#include "LED_control.h"

void update_LEDS(uint8_t led1, uint8_t led2, uint8_t led3,uint8_t led4)
{
	if(led1 == 0xff)
	{
		led1 = 0xfe;
	}
	if(led2 == 0xff)
	{
		led2 = 0xfe;
	}
	if(led3 == 0xff)
	{
		led3 = 0xfe;
	}
	if(led4 == 0xff)
	{
		led4 = 0xfe;
	}
	temp_compare_led_array_2[0] = 255 -led1;//Led1
	temp_compare_led_array_2[1] = 255 -led2;//led2
	temp_compare_led_array_2[2] = 255 -led3;//Led3
	temp_compare_led_array_2[3] =  led4;//Led3
	initializing_LED_pin_array();
	increasing_LED_sort_tag();
	LED_transfer_temp();
	update_compare_led_array = true;
}

void update_LEDS_single(uint8_t port_no, uint8_t led)
{
	if(led == 0xff)
	{
		led = 0xfe;
	}
	switch (port_no)
	{
		case '1':
					temp_compare_led_array_2[0] = 255 -led;//Led1
					break;
		case '2':
					temp_compare_led_array_2[1] = 255 -led;//Led2
					break;
		case '3':
					temp_compare_led_array_2[2] = 255 -led;//Led3
					break;
		case '4':
					temp_compare_led_array_2[3] = led;//Led4
					break;
		default:
					break;
	}
	initializing_LED_pin_array();
	increasing_LED_sort_tag();
	LED_transfer_temp();
	update_compare_led_array = true;
}


void switch_off_LEDS()
{
	temp_compare_led_array_2[0] = 255; //Led1
	temp_compare_led_array_2[1] = 255; //Led2
	temp_compare_led_array_2[2] = 255; //Led3
	temp_compare_led_array_2[3] = 0; //Led4
	initializing_LED_pin_array();
	increasing_LED_sort_tag();
	LED_transfer_temp();
	update_compare_led_array = true;
}


