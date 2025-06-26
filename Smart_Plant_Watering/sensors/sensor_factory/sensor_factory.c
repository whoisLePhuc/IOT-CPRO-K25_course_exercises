#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "sensor_factory.h"
#include "../moisture/moisture.h"
#include "../temperature/temperature.h"

// Factory method to create sensor based in their type
Sensor* createSensor(sensorType type){
    Sensor *sensor = (Sensor*)malloc(sizeof(Sensor));
    if(sensor == NULL){
        printf("[SENSOR_FACTORY]: Create Function Failed\n");
        return NULL;
    }
    switch (type){
        case SENSOR_TEMPERATURE:
            sensor = createTemperatureSensor();
            break;
        case SENSOR_MOISTURE:
            sensor = createMoistureSensor();
            break;
        default:
            free(sensor);
            return NULL;
    }
    return sensor;
}