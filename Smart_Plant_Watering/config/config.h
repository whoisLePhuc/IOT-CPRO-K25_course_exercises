#ifndef CONFIG_H
#define CONFIG_H
#include "sensors/sensor_factory/sensors.h"
#include <stdint.h>
// Struct for system mode
typedef enum{
    AUTO_MODE,
    MANUAL_MODE
}SystemMode;

// Struct for pump state
typedef enum{
    PUMP_OFF,
    PUMP_ON
}PumpState;

// Struct for LED state
typedef enum{
    LED_NORMAL,
    LED_WATERING,
    LED_LOW_MOISTURE_ALERT,
    LED_ERROR
}LedState;

// Struct for watering system configuration
typedef struct{
    uint8_t minMoisture;
    uint8_t maxMoisture;
    uint16_t maxWateringTime;
    unsigned int sensorCheckInterval;
}WateringSettings;

// Structer for all kinds of sensors data
typedef struct{
    Sensor *temperatureSensor;
    Sensor *moistureSensor;
    float temperatureData;
    float moistureData;
}SensorsData;

// Function for initialize configuration of system
WateringSettings *initWateringSettings(uint8_t minMoisture, uint8_t maxMoisture, uint16_t maxWateringTime, uint16_t sensorCheckInterval);
SensorsData *initSensorsData(Sensor *temperatureSensor, Sensor *moistureSensor);
extern SystemMode systemMode;

#endif