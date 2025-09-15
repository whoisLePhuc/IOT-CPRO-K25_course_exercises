#include <stdio.h> 
#include <stdlib.h>
#include "config.h"

// Function to initialize watering settings
ThreadholdSettings *initThreadholdSettings(uint8_t minMoisture, uint8_t maxMoisture, uint16_t maxWateringTime, uint16_t sensorCheckInterval) {
    ThreadholdSettings *settings = (ThreadholdSettings *)malloc(sizeof(ThreadholdSettings));
    if (settings == NULL) {
        fprintf(stderr, "[CONFIG]: Memory allocation failed for Threadhold Settings\n");
        return NULL;
    }
    settings->minMoisture = minMoisture;
    settings->maxMoisture = maxMoisture;
    settings->maxWateringTime = maxWateringTime;
    settings->sensorCheckInterval = sensorCheckInterval;

    return settings;
}