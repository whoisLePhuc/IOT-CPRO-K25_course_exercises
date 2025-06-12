#include <stdio.h>
#include <stdlib.h>
#include "hvac.h"

static void setTemperature(int temperature) {
    printf("Setting HVAC temperature to %d degrees.\n", temperature);
}

static void setMode(const char* mode) {
    printf("Setting HVAC mode to %s.\n", mode);
}

// Function to create an instance of HvacSystem
HvacSystem* createHvacSystem() {
    HvacSystem* system = (HvacSystem*)malloc(sizeof(HvacSystem));
    system->setTemperature = setTemperature; 
    system->setMode = setMode;
    return system;
}