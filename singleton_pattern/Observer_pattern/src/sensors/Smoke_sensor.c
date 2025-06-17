#include "inc/sensors/Smoke_sensor.h"
#include <stdio.h>

void SmokeSensorInit(SmokeSensor* sensor, const char* location) {
    PublisherInit(&sensor->Base, "SmokeSensor");
    sensor->location = location;
}

void SmokeSensorDetect(SmokeSensor* sensor, unsigned long time){
    Event event;
    event.type = EVT_SMOKE_DETECTED;
    event.location = sensor->location;
    event.level = 0; 
    event.time = time;
    sensor->Base.notify(&sensor->Base, &event);
}



