#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "moisture.h"

// Initialize sensor function
void moistureSensorInit(){
    printf("[MOISTURE]: Moisture sensor initialized\n");
}

// Read sensor function
float moistureSensorReadData(){
    return (rand() % (99 - 20 + 1)) + 20; // simulated value
}

// Function to create Sensor class
Sensor* createMoistureSensor(){
    Sensor* sensor = (Sensor*)malloc(sizeof(Sensor));
    sensor->init = moistureSensorInit;
    sensor->readData = moistureSensorReadData;
    return sensor;
}