/*
 * sensor.c
 *
 * Created: 12/7/2017 2:46:00 PM
 *  Author: raghu
 */ 
#include <asf.h>
#include "sensor.h"

struct adc_module adc_instance;



void configure_adc()
{
	struct adc_config conf_adc;
	adc_get_config_defaults(&conf_adc);
	
	//conf_adc.clock_source = GCLK_GENERATOR_1;
	conf_adc.reference			= ADC_REFERENCE_INTVCC0;
	conf_adc.clock_prescaler	= ADC_CLOCK_PRESCALER_DIV4;
	conf_adc.positive_input		= SENSOR1;
	conf_adc.negative_input		= ADC_NEGATIVE_INPUT_GND;
	conf_adc.resolution			= ADC_RESOLUTION_8BIT;
	//conf_adc.left_adjust		= true;
	
	adc_init(&adc_instance, ADC, &conf_adc);
	adc_enable(&adc_instance);
}


uint8_t adc_start_read_result(const enum adc_positive_input analogPin)
{
	volatile uint16_t adc_result = 0;
	adc_set_positive_input(&adc_instance, analogPin);
	adc_start_conversion(&adc_instance);
	while((adc_get_status(&adc_instance) & ADC_STATUS_RESULT_READY) != 1);
	adc_read(&adc_instance, &adc_result);
	return adc_result;
}


void sensor_init()
{
	//Enable Analog input 
	configure_adc();
}