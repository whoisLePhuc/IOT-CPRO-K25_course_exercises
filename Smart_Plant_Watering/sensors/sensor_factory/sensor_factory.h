#ifndef SENSOR_FACTORY_H
#define SENSOR_FACTORY_H

#include "sensors.h"

// ennum to represent sensor types
typedef enum{
    SENSOR_TEMPERATURE,
    SENSOR_MOISTURE
} sensorType;

// Factory method to create sensor based in their type
Sensor* createSensor(sensorType type);

#endif
