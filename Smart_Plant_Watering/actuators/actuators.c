#include <stdio.h>
#include <stdlib.h>
#include "actuators.h"
#include "config/config.h"

// Function prototypes for pump operations
void pumpOn() {
    printf("[PUMP]: Pump turned ON\n");
}

void pumpOff() {
    printf("[PUMP]: Pump turned OFF\n");
}

void pumpInit(Pump *pump) {
    if (pump == NULL) {
        fprintf(stderr, "[PUMP]: Pump is NULL\n");
        return;
    }
    pump->on = pumpOn;
    pump->off = pumpOff;
    printf("[PUMP]: Pump initialized\n");
}

// Function prototypes for LED operations
void turnLedNormal(){
    printf("[LED]: LED turned to NORMAL state\n");
}

void turnLedLowMoistureAlert(){
    printf("[LED]: LED turned to LOW MOISTURE ALERT state\n");
}

void turnLedWatering(){
    printf("[LED]: LED turned to WATERING state\n");
}

void turnLedError(){
    printf("[LED]: LED turned to ERROR state\n");
}

void ledInit(Led *led){
    if(led == NULL){
        fprintf(stderr, "[LED]: LED is NULL\n");
        return;
    }
    led->turnLedNormal = turnLedNormal;
    led->turnLedLowMoistureAlert = turnLedLowMoistureAlert;
    led->turnLedWatering = turnLedWatering;
    led->turnLedError = turnLedError;
    printf("[LED]: LED initialized\n");
}