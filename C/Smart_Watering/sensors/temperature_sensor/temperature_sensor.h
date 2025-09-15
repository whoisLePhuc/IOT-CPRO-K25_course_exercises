#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H
#include "../sensor_factory/sensor.h"

void Temperature_Sensor_Init(); // Function to initialize the Temperature sensor
float Read_Data_Temperature_Sensor(); // Function to read data from the Temperature sensor
Sensor Create_Temperature_Sensor(); // Function to create a Temperature sensor

#endif