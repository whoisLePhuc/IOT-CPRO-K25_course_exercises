#include <stdio.h>
#include "logger/logger.h"
#include "led.h"

void turnOnLedNormal(){
    logMessage(LOG_DEBUG, "Led normal is turned ON.");
}

void turnOnLedWatering(){
    logMessage(LOG_DEBUG, "Led watering is turned ON.");
}

void turnOnLedLowMoisture(){
    logMessage(LOG_DEBUG, "Led low moisture is turned ON.");
}

void turnOnLedError(){
    logMessage(LOG_DEBUG, "Led error is turned ON.");
}