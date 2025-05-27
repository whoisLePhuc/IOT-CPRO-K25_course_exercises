#include <stdio.h>
#include <humidity_sensor/humidity_sensor.h>

void Humidity_Sensor_Init() {
    printf("Humidity sensor initialized.\n");
}

float Read_Data_Humidity_Sensor() {
    return 45.0; // Simulated value
}

Sensor Create_Humidity_Sensor() {
    Sensor Humidity_Sensor;
    Humidity_Sensor.Init = Humidity_Sensor_Init;
    Humidity_Sensor.Read_Data = Read_Data_Humidity_Sensor;
    return Humidity_Sensor;
}