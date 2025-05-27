#include <stdio.h>
#include "sensor_factory/sensor_factory.h"

int main(){

    Sensor *humidity_sensor = Create_Sensor(SENSOR_HUMIDITY);
    if(humidity_sensor != NULL){
        humidity_sensor->Init();
        printf("Humidity: %.2f%%\n", humidity_sensor->Read_Data(0.0));
        free(humidity_sensor);
    }

    Sensor *light_sensor = Create_Sensor(SENSOR_LIGHT);
    if(light_sensor != NULL){
        light_sensor->Init();
        printf("Light Intensity: %.2f lux\n", light_sensor->Read_Data(0.0));
        free(light_sensor);
    }
    return 0;
}
