#include <stdio.h>
#include "temperature_sensor.h"

// Initializes the temperature sensor hardware
void Temperature_Sensor_Init() {
    printf("Temperature sensor initialized.\n");
}

//Reads temperature data from the sensor
float Read_Data_Temperature_Sensor() {
    return 50.0; // Simulated temperature value for demonstration
}

// Creates a temperature sensor instance
Sensor Create_Temperature_Sensor() {
    Sensor Temperature_Sensor;
    Temperature_Sensor.Init = Temperature_Sensor_Init;
    Temperature_Sensor.Read_Data = Read_Data_Temperature_Sensor;
    return Temperature_Sensor;
}