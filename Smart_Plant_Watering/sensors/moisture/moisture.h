#ifndef MOISTURE_SENSOR_H
#define MOISTURE_SENSOR_H

#include "../sensor_factory/sensors.h"

//Function prototype for the moisture sensor
void moistureSensorInit();
float moistureSensorReadData();
Sensor* createMoistureSensor();

#endif