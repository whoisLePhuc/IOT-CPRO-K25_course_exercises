#ifndef HUMIDITY_SENSOR_H
#define HUMIDITY_SENSOR_H
#include "../sensor_factory/sensor.h"

void Humidity_Sensor_Init(); // Function to initialize the humidity sensor
float Read_Data_Humidity_Sensor(); // Function to read data from the humidity sensor
Sensor Create_Humidity_Sensor(); // Function to create a humidity sensor

#endif