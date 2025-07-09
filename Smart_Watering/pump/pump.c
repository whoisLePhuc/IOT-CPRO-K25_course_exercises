#include <stdio.h>
#include "logger/logger.h"
#include "pump.h"

void turnPumpOn() {
    // Code to turn the pump on
    logMessage(LOG_DEBUG, "Pump is turned ON");
}

void turnPumpOff() {
    // Code to turn the pump off
    logMessage(LOG_DEBUG, "Pump is turned OFF");
}