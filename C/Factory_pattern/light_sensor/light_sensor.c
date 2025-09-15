#include <stdio.h>
#include <light_sensor/light_sensor.h>

void Init_light_Sensor(){
    printf("Light sensor initialized.\n");
}

float Read_Data_light_Sensor(){
    return 300.0; // Simulated value
}

Sensor Create_Light_Sensor(){
    Sensor Light_Sensor;
    Light_Sensor.Init = Init_light_Sensor;
    Light_Sensor.Read_Data = Read_Data_light_Sensor;
    return Light_Sensor;
}

