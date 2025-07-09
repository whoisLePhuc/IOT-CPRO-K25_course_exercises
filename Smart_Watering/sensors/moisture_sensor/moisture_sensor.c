#include <stdio.h>
#include "moisture_sensor.h"

// Initializes the moisture sensor hardware
void Moisture_Sensor_Init() {
    printf("Moisture sensor initialized.\n");
}

// Reads moisture data from the sensor
float Read_Data_Humidity_Sensor() {
    return 45.0; // Simulated moisture value for demonstration
}

// Function to creates a moisture sensor instance
Sensor Create_Moisture_Sensor() {
    Sensor Moisture_Sensor;
    Moisture_Sensor.Init = Moisture_Sensor_Init;
    Moisture_Sensor.Read_Data = Read_Data_Humidity_Sensor;
    return Moisture_Sensor;
}