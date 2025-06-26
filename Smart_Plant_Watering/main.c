#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
#include "config/config.h"
#include "sensors/sensor_factory/sensor_factory.h"
#include "system/system.h"
#include "actuators/actuators.h"

void delay(unsigned int milliseconds);
unsigned long millis();
static int watering_flag = 0; // Variable to check if watering is in progress
unsigned long lastWateringTime = 0; // Variable to store the last watering time
unsigned long lastSensorUpdateTime = 0; // Variable to store the last sensor update time
unsigned long lastLoopUpdateTime = 0; // Variable to store the last sensor update time

int main(){
    // minMoisture, maxMoisture, maxWateringTime - s, sensorCheckInterval - s
    WateringSettings *wateringSettings = initWateringSettings(60, 70, 10, 5);
    if (wateringSettings == NULL) {
        fprintf(stderr, "[Main]: Failed to initialize watering settings\n");
        return 0;
    }
    // Initialize sensors using factory method
    Sensor *temperatureSensor = createSensor(SENSOR_TEMPERATURE);
    if (temperatureSensor == NULL) {
        fprintf(stderr, "[Main]: Failed to create temperature sensor\n");
        free(wateringSettings);
        return 0;
    }
    Sensor *moistureSensor = createSensor(SENSOR_MOISTURE);
    if (moistureSensor == NULL) {
        fprintf(stderr, "[Main]: Failed to create moisture sensor\n");
        free(temperatureSensor);
        free(wateringSettings);
        return 0;
    }
    SensorsData *sensorsData = initSensorsData(temperatureSensor, moistureSensor);
    if (sensorsData == NULL) {
        fprintf(stderr, "[Main]: Failed to initialize sensors data\n");
        free(temperatureSensor);
        free(moistureSensor);
        free(wateringSettings);
        return 0;
    }
    // Initialize system 
    System *system = createSystem(*wateringSettings, *sensorsData);
    if (system == NULL) {
        fprintf(stderr, "[Main]: Failed to create system\n");
        free(sensorsData);
        free(moistureSensor);
        free(temperatureSensor);
        free(wateringSettings);
        return 0;
    } else {
        printf("[Main]: System initialized successfully\n");
    }
    // Initialize actuators
    Pump pump;
    Led led;
    ledInit(&led);
    pumpInit(&pump);
    // Set initial mode to AUTO_MODE
    system->clickAutoButton(system);
    system->updateSensorData(system);
    // main loop
    unsigned long currentMillis = 0;
    while(1){
        currentMillis = millis();
        // update sensor, pump, and led state every second
        if(currentMillis - lastLoopUpdateTime >= 100){
            printf("\n");
            // Using millis to control the sensor loop update interval
            if(currentMillis - lastSensorUpdateTime >= system->settings.sensorCheckInterval * 1000){
                system->updateSensorData(system);
                lastSensorUpdateTime = currentMillis; // Update last sensor update time
                printf("[Main]: Temperature: %.2f, Moisture: %.2f\n", system->sensorsData.temperatureData, system->sensorsData.moistureData);
                // Update pump and led state based on sensor data
                system->setPumpState(system);
                system->setLedState(system);
            }
            // Check if watering is needed based on moisture data
            if(watering_flag == 0){
                switch(system->pumpState){
                    case PUMP_ON:
                        pump.on();
                        watering_flag = 1; // Set flag to indicate watering is in progress
                        lastWateringTime = currentMillis; // Update last watering time here
                        break;
                    case PUMP_OFF:
                        pump.off();
                        watering_flag = 0; 
                        break;
                    default:
                        fprintf(stderr, "[Main]: Unknown pump state\n");
                }
                switch(system->ledState){
                    case LED_ERROR:
                        led.turnLedError();
                        break;
                    case LED_NORMAL:
                        led.turnLedNormal();
                        break;
                    case LED_WATERING: // because watering_flag is 0, this case will not be executed
                        break;
                    case LED_LOW_MOISTURE_ALERT:
                        led.turnLedLowMoistureAlert();
                        break;
                    default:
                        fprintf(stderr, "[Main]: Unknown LED state\n");
                        break;
                }
            }else if(watering_flag == 1){
                // turn on the watering LED
                led.turnLedWatering();
                // Check if watering time exceeds maxWateringTime
                if(currentMillis - lastWateringTime >= system->settings.maxWateringTime * 1000){
                    pump.off();
                    watering_flag = 0; // Reset flag after watering is done
                } else {
                    // Continue watering
                    printf("[Main]: Watering in progress...\n");
                }
            }
        lastLoopUpdateTime = currentMillis; // Update last loop update time
        }
    }
    return 0;
}

void delay(unsigned int milliseconds) {
    #ifdef _WIN32
        Sleep(milliseconds);
    #else
        usleep(milliseconds * 1000); // Convert milliseconds to microseconds
    #endif
}

unsigned long millis() {
    #ifdef _WIN32
        return GetTickCount();
    #else
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        return (ts.tv_sec * 1000) + (ts.tv_nsec / 1000000);
    #endif
}