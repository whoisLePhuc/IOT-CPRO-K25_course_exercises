#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "system.h"
#include "sensors/sensor_factory/sensor_factory.h"
#include "config/config.h"

void clickAutoButton(System *self) {
    if (self == NULL) {
        fprintf(stderr, "[SYSTEM]: System is NULL\n");
        return;
    }
    self->setMode(self, AUTO_MODE);
    printf("[SYSTEM]: Switched to Auto Mode\n");
}

void clickManualButton(System *self) {
    if (self == NULL) {
        fprintf(stderr, "System is NULL\n");
        return;
    }
    self->setMode(self, MANUAL_MODE);
    printf("[SYSTEM]: Switched to Manual Mode\n");
}

float readSensorsData(System *self, sensorType type) {
    if (self == NULL) {
        fprintf(stderr, "[SYSTEM]: System is NULL\n");
        return 0;
    }
    float value = 0.0f;
    switch(type){
        case SENSOR_TEMPERATURE:
            if (self->sensorsData.temperatureSensor == NULL) {
                fprintf(stderr, "[SYSTEM]: Temperature sensor is not initialized\n");
                return 0;
            }
            value = self->sensorsData.temperatureSensor->readData();
            break;
        case SENSOR_MOISTURE:
            if (self->sensorsData.moistureSensor == NULL) {
                fprintf(stderr, "[SYSTEM]: Moisture sensor is not initialized\n");
                return 0;
            }
            value = self->sensorsData.moistureSensor->readData();
            break;
        default:
            fprintf(stderr, "[SYSTEM]: Unknown sensor type\n");
            return 0;
    }
    return value;
}

void setLedState(System *self) {
    if (self == NULL) {
        fprintf(stderr, "[SYSTEM]: System is NULL\n");
        return;
    }
    switch (self->currentMode) {
        case AUTO_MODE:
            if (self->sensorsData.moistureData < self->settings.minMoisture){
                switch (self->pumpState) {
                    case PUMP_OFF:
                        self->ledState = LED_LOW_MOISTURE_ALERT;
                        break;
                    case PUMP_ON:
                        self->ledState = LED_WATERING;
                        break;
                    default:
                        self->ledState = LED_ERROR;
                        break;
                }
            } else{
                self->ledState = LED_NORMAL;
            }
            break;
        case MANUAL_MODE:
            // In manual mode, we can set the LED to a specific state if needed
            break;
        default:
            self->ledState = LED_ERROR;
            break;
    }
    printf("[SYSTEM]: LED state set to %d\n", self->ledState);
}

void setPumpState(System *self) {
    if (self == NULL) {
        fprintf(stderr, "[SYSTEM]: System is NULL\n");
        return;
    }
    if (self->currentMode == AUTO_MODE) {
        if (self->sensorsData.moistureData  < self->settings.minMoisture) {
            self->pumpState = PUMP_ON;
        } else {
            self->pumpState = PUMP_OFF;
        }
    } else if (self->currentMode == MANUAL_MODE) {
        // In manual mode, we can set the pump state based on user input
        // For now, we will just turn it off
        self->pumpState = PUMP_OFF;
    } else {
        self->pumpState = PUMP_OFF; // Default to off for unknown modes
    }
    printf("[SYSTEM]: Pump state set to %d\n", self->pumpState);
}

void setMode(System *self, SystemMode newMode) {
    if (self == NULL) {
        fprintf(stderr, "[SYSTEM]: System is NULL\n");
        return;
    }
    self->currentMode = newMode;
    printf("[SYSTEM]: Mode set to %d\n", newMode);
}

void updateSensorData(System *self){
    if (self == NULL) {
        fprintf(stderr, "[SYSTEM]: System is NULL\n");
        return;
    }
    if (self->sensorsData.temperatureSensor != NULL) {
        self->sensorsData.temperatureData = self->sensorsData.temperatureSensor->readData();
        printf("[SYSTEM]: Updated temperature data: %.2f\n", self->sensorsData.temperatureData);
    } else {
        fprintf(stderr, "[SYSTEM]: Temperature sensor is not initialized\n");
    }
    
    if (self->sensorsData.moistureSensor != NULL) {
        self->sensorsData.moistureData = self->sensorsData.moistureSensor->readData();
        printf("[SYSTEM]: Updated moisture data: %.2f\n", self->sensorsData.moistureData);
    } else {
        fprintf(stderr, "[SYSTEM]: Moisture sensor is not initialized\n");
    }
}

System *createSystem( WateringSettings settings, SensorsData sensorsData) {
    System *system = (System *)malloc(sizeof(System));
    if (system == NULL) {
        fprintf(stderr, "[SYSTEM]: Memory allocation failed for System\n");
        return NULL;
    }
    system->currentMode = AUTO_MODE; // Default mode
    system->ledState = LED_NORMAL; // Default LED state
    system->pumpState = PUMP_OFF; // Default pump state
    system->settings = settings;
    system->sensorsData = sensorsData;
    system->setLedState = setLedState;
    system->setPumpState = setPumpState;
    system->updateSensorData = updateSensorData;
    system->setMode = setMode;
    system->readSensorsData = readSensorsData;
    system->clickAutoButton = clickAutoButton;
    system->clickManualButton = clickManualButton;

    return system;
}

