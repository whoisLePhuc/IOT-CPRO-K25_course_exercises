#include <stdio.h>
#include <stdlib.h>
#include "config.h"

// Function to initialize watering settings
WateringSettings *initWateringSettings(uint8_t minMoisture, uint8_t maxMoisture, uint16_t maxWateringTime, uint16_t sensorCheckInterval) {
    WateringSettings *settings = (WateringSettings *)malloc(sizeof(WateringSettings));
    if (settings == NULL) {
        fprintf(stderr, "[CONFIG]: Memory allocation failed for WateringSettings\n");
        return NULL;
    }
    settings->minMoisture = minMoisture;
    settings->maxMoisture = maxMoisture;
    settings->maxWateringTime = maxWateringTime;
    settings->sensorCheckInterval = sensorCheckInterval;
    return settings;
}

// Function to initialize sensors data
SensorsData *initSensorsData(Sensor *temperatureSensor, Sensor *moistureSensor) {
    SensorsData *sensorsData = (SensorsData *)malloc(sizeof(SensorsData));
    if (sensorsData == NULL) {
        fprintf(stderr, "[CONFIG]: Memory allocation failed for SensorsData\n");
        return NULL;
    }
    sensorsData->temperatureSensor = temperatureSensor;
    sensorsData->moistureSensor = moistureSensor;
    sensorsData->temperatureData = 0.0f; // Initialize with default value
    sensorsData->moistureData = 0.0f; // Initialize with default
    return sensorsData;
}