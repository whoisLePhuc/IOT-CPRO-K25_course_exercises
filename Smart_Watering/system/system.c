#include <stdio.h>
#include <stdlib.h>
#include "system/system.h"
#include "system/config/config.h"

System *initSystem(uint8_t minMoisture, uint8_t maxMoisture, uint16_t maxWateringTime, uint16_t sensorCheckInterval) {
    System *f_system = (System *)malloc(sizeof(System));
    if (f_system == NULL) {
        fprintf(stderr, "[SYSTEM]: Memory allocation failed for System\n");
        return NULL;
    }
    f_system->currentMode = AUTO_MODE;
    f_system->settings = initTShreadholdSettings(minMoisture, maxMoisture, maxWateringTime, sensorCheckInterval);
    if (f_system->settings == NULL) {
        free(f_system);
        return NULL;
    }

    f_system->sensorsData.moisture = 0.0f;
    f_system->sensorsData.temperature = 0.0f;

    return system;
}