#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "temperature.h"

// Function to initialize sensor
void temperatureSensorInit(){
    printf("[TEMPERATURE]: Temperature sensor initialized\n");
}

// Function to read sensor
float temperatureSensorReadData(){
    return (rand() % (50 - 15 + 1)) + 50;
}


// Function to create temperature sensor class
Sensor* createTemperatureSensor(){
    Sensor* sensor = (Sensor*)malloc(sizeof(Sensor));
    sensor->init = temperatureSensorInit;
    sensor->readData = temperatureSensorReadData;
    return sensor;
}