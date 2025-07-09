#ifndef SYSTEM_H
#define SYSTEM_H

#include"config/config.h"
#include"sensors/sensor_factory/sensor_factory.h"


typedef enum{
    AUTO_MODE,      
    MANUAL_MODE     
}SystemMode;

// Sensor data structure
typedef struct{
    float moisture;     // (%)
    float temperature;  // (°C)
}SensorsData;

typedef struct System System;

// Main system structure
struct System{
    SystemMode currentMode;        
    ThreadholdSettings *settings;  
    SensorsData sensorsData;       
};

// Function to initialize system instance
System *initSystem(uint8_t minMoisture, uint8_t maxMoisture, uint16_t maxWateringTime, uint16_t sensorCheckInterval);

#endif