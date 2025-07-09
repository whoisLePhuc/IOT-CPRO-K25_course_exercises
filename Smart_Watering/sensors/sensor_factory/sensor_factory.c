#include <stdio.h>
#include "sensor_factory.h"
#include "../moisture_sensor/moisture_sensor.h"
#include "../temperature_sensor/temperature_sensor.h"

Sensor* Create_Sensor(Sensor_Type type){
    // Allocate memory for sensor instance
    Sensor* sensor = (Sensor*)malloc(sizeof(Sensor));
    if (sensor == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    
    // Create sensor based on requested type
    switch(type){
        case SENSOR_TEMPERATURE:
            *sensor = Create_Temperature_Sensor();
            break;
        case SENSOR_MOISTURE:
            *sensor = Create_Moisture_Sensor();
            break;
        default:
            printf("Invalid sensor type.\n");
            free(sensor);
            return NULL; // Invalid sensor type
    }
    return sensor;
}
