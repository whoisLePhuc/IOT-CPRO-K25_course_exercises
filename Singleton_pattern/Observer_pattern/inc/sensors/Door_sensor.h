#ifndef DOOR_SENSOR_H
#define DOOR_SENSOR_H

#include "inc/publisher.h"

typedef struct{
    Publisher Base;
    const char* location;
}DoorSensor;

void DoorSensorInit(DoorSensor* sensor, const char* location);
void DoorSensorOpen(DoorSensor* sensor, unsigned long time);
void DoorSensorClose(DoorSensor* sensor, unsigned long time);

#endif