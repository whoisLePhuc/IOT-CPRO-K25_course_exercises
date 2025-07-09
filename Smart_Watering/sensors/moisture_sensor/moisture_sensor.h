#ifndef MOISTURE_SENSOR_H
#define MOISTURE_SENSOR_H
#include "../sensor_factory/sensor.h"

void Moisture_Sensor_Init(); // Function to initialize the moisture sensor
float Read_Data_Moisture_Sensor(); // Function to read data from the moisture sensor
Sensor Create_Moisture_Sensor(); // Function to create a moisture sensor

#endif