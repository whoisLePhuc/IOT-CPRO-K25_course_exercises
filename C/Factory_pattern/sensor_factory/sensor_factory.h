#ifndef SENSOR_FACTORY_H
#define SENSOR_FACTORY_H
#include "sensor.h"

// Sensor types
typedef enum {
    SENSOR_TEMPERATURE,
    SENSOR_HUMIDITY,
    SENSOR_LIGHT
}Sensor_Type;

Sensor *Create_Sensor(Sensor_Type type); // Factory function to create a sensor based on the type

#endif
