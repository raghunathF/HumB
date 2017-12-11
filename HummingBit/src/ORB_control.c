/*
 * ORB_control.c
 *
 * Created: 12/8/2017 9:44:53 AM
 *  Author: raghu
 */ 

#include <asf.h>
#include "ORB_control.h"
#include "ORB.h"

void update_ORB(uint8_t r1 ,uint8_t g1 ,uint8_t b1 ,uint8_t r2 ,uint8_t b2 ,uint8_t g2  )
{
 	temp_compare_array[0] = 255-r1;//Left -- R
 	temp_compare_array[1] = 255-g1;//Left  -- G
 	temp_compare_array[2] = 255-b1;//Left  -- B
 	temp_compare_array[3] = 255-r2;//Right -- R
 	temp_compare_array[4] = 255-b2;//Right  -- G
 	temp_compare_array[5] = 255-g2;//Right -- B
	initializing_pin_array();
	increasing_sort_tag();
	transfer_temp();
	update_compare_array = true;
}



