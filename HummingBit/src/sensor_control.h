/*
 * sensor_control.h
 *
 * Created: 12/7/2017 3:33:47 PM
 *  Author: Raghunath 
 */ 


#ifndef SENSOR_CONTROL_H_
#define SENSOR_CONTROL_H_

extern uint8_t* global_sensor_value;
uint32_t read_all_sensors();

#define SENSOR1_AI  6
#define SENSOR2_AI  9
#define SENSOR3_AI  8
#define VOLTAGE_MTR_AI 0 

#define SENSORS_AI {SENSOR1_AI ,SENSOR2_AI, SENSOR3_AI, VOLTAGE_MTR_AI};

#define ALL_SENSORS {SENSOR1, SENSOR2 , SENSOR3 ,VOLTAGE_MTR} 
#define NO_SENSORS 4

#endif /* SENSOR_CONTROL_H_ */