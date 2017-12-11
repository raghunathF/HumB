/*
 * CFile1.c
 *
 * Created: 12/7/2017 3:33:13 PM
 *  Author: raghu
 */ 
#include <asf.h>
#include "sensor_control.h"
#include "sensor.h"
static const  uint8_t sensor_analog_inputs[NO_SENSORS] = SENSORS_AI;


//0-- sensor-1 , 1-- sensor-2 , 2-- sensor-3 , 3- Volatge_mtr
uint8_t read_sensor(uint8_t sensor_no)
{
	uint8_t output_single_adc = 0;
	output_single_adc = adc_start_read_result(sensor_analog_inputs[sensor_no]);
	return output_single_adc;
}

uint32_t read_all_sensors()
{
	uint32_t output_multiple_adc = 0;
	uint32_t temp =0;
	
	uint8_t i =0;
	for(i= 0; i< NO_SENSORS; i++)
	{
		temp = adc_start_read_result(sensor_analog_inputs[i]);
		temp = temp<<8*i;
		output_multiple_adc = temp | output_multiple_adc;
		
	}
	//global_sensor_value = &output_multiple_adc;
	return output_multiple_adc;
}