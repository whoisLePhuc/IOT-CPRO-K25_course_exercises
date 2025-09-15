#ifndef SENSOR_FACTORY_H
#define SENSOR_FACTORY_H
#include "sensor.h"
#include <stdlib.h>

// Available sensor types
typedef enum {
    SENSOR_TEMPERATURE, 
    SENSOR_MOISTURE      
}Sensor_Type;

// Factory function to create sensor instances
Sensor *Create_Sensor(Sensor_Type type);

#endif
