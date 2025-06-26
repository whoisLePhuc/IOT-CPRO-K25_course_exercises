#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "../sensor_factory/sensors.h"

//Function prototype for the moisture sensor
void temperatureSensorInit();
float temperatureSensorReadData();
Sensor* createTemperatureSensor();

#endif