#include <stdio.h>
#include "sensor_factory.h"
#include "../light_sensor/light_sensor.h"
#include "../humidity_sensor/humidity_sensor.h"

// Function to create a sensor based on the type
Sensor* Create_Sensor(Sensor_Type type){
    Sensor* sensor = (Sensor*)malloc(sizeof(Sensor));
    if (sensor == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    switch(type){
        case SENSOR_LIGHT:
            *sensor = Create_Light_Sensor();
            break;
        case SENSOR_HUMIDITY:
            *sensor = Create_Humidity_Sensor();
            break;
        default:
            printf("Invalid sensor type.\n");
            free(sensor);
            return NULL; // Invalid sensor type
    }
    return sensor;
}
