#ifndef CONFIG_H
#define CONFIG_H
#include <stdint.h>

// System configuration structure
typedef struct{
    uint8_t minMoisture;           // (%)
    uint8_t maxMoisture;           // (%)
    uint16_t maxWateringTime;      // (seconds)
    unsigned int sensorCheckInterval; // (seconds)
}ThreadholdSettings;

// Function to initialize threadhold setting
ThreadholdSettings *initThreadholdSettings(uint8_t minMoisture, uint8_t maxMoisture, uint16_t maxWateringTime, uint16_t sensorCheckInterval);

#endif // CONFIG_H