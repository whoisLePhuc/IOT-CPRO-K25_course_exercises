#include <stdio.h>
#include <stdlib.h>
#include "smart_home_facade.h"
#include "../light/light.c"
#include "../security/security.c"
#include "../hvac/hvac.c"

// Function to create an instance of SmartHomeFacade
SmartHomeFacade* createSmartHomeFacade() {
    SmartHomeFacade* facade = (SmartHomeFacade*)malloc(sizeof(SmartHomeFacade));
    facade->security = createSercuritySystem();
    facade->light = createLightSystem();
    facade->hvac = createHvacSystem();
    return facade;
}

// Function to create the morning routine
void activateMorningRoutine(SmartHomeFacade* facade) {
    facade->security->deactivateSercuritySystem();
    facade->light->turnOn();
    facade->light->setBrightness(75);
    facade->hvac->setTemperature(22);
    facade->hvac->setMode("cooling");
    printf("Activating morning routine...\n");
}

// Function to active the away mode
void activateAwayMode(SmartHomeFacade* facade) {
    facade->security->activateSercuritySystem();
    facade->light->turnOff();
    facade->hvac->setTemperature(26);
    facade->hvac->setMode("eco");
    printf("Activating away mode...\n");
}

// function to set the movie night scene
void setMovieNightScene(SmartHomeFacade* facade) {
    facade->security->deactivateSercuritySystem();
    facade->light->turnOn();
    facade->light->setBrightness(30);
    facade->hvac->setTemperature(20);
    facade->hvac->setMode("cooling");
    printf("Setting movie night scene...\n");
}