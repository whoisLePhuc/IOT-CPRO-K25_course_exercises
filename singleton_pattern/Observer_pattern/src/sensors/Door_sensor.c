#include "inc/sensors/Door_sensor.h"
#include <stdio.h>

void DoorSensorInit(DoorSensor* sensor, const char* location) {
    PublisherInit(&sensor->Base, "DoorSensor");
    sensor->location = location;
}

void DoorSensorOpen(DoorSensor* sensor, unsigned long time){
    Event event;
    event.type = EVT_DOOR_OPEN;
    event.location = sensor->location;
    event.level = 0; // Level is not used for door events, set to 0
    event.time = time;
    sensor->Base.notify(&sensor->Base, &event);
}

void DoorSensorClose(DoorSensor* sensor, unsigned long time){
    Event event;
    event.type = EVT_DOOR_CLOSE;
    event.location = sensor->location;
    event.level = 0; // Level is not used for door events, set to 0
    event.time = time;
    sensor->Base.notify(&sensor->Base, &event);
}

