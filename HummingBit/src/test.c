/*
 * test.h
 *
 * Created: 12/8/2017 4:45:50 PM
 *  Author: raghu
 */ 


#ifndef TEST_H_
#define TEST_H_

#include <asf.h>
#include "LED_control.h"
#include "ORB_control.h"
#include "test.h"
#include "delay.h"

void test_ORB()
{
	int i =0;
	
	//
	for(i=0;i<=255;i++)
	{
		update_ORB(i,0,0,i,0,0);
		delay_cycles_ms(20);
	}
	for(i=255;i>=0;i--)
	{
		update_ORB(i,0,0,i,0,0);
		delay_cycles_ms(20);
	}
	//
	for(i=0;i<=255;i++)
	{
		update_ORB(0,i,0,0,i,0);
		delay_cycles_ms(20);
	}
	for(i=255;i>=0;i--)
	{
		update_ORB(0,i,0,0,i,0);
		delay_cycles_ms(20);
	}
	//
	for(i=0;i<=255;i++)
	{
		update_ORB(0,0,i,0,0,i);
		delay_cycles_ms(20);
	}
	for(i=255;i>=0;i--)
	{
		update_ORB(0,0,i,0,0,i);
		delay_cycles_ms(20);
	}

}

void test_LED()
{
	
}

#endif /* TEST_H_ */