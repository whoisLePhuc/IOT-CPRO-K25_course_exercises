#ifndef SMOKE_SENSOR_H
#define SMOKE_SENSOR_H

#include "inc/publisher.h"

typedef struct{
    Publisher Base;
    const char* location;
}SmokeSensor;

void SmokeSensorInit(SmokeSensor* sensor, const char* location);
void SmokeSensorDetect(SmokeSensor* sensor, unsigned long time);

#endif