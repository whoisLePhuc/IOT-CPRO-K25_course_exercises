#include <stdio.h>
#include <stdlib.h>
#include "light.h"

static void turnOn(){
    printf("Turning on the light.\n");
}

static void turnOff(){
    printf("Turning off the light.\n");
}

static void setBrightness(int brightness){
    printf("Setting light brightness to %d%%.\n", brightness);
}

// Function to create an instance of LightSystem
LightSystem* createLightSystem() {
    LightSystem* system = (LightSystem*)malloc(sizeof(LightSystem));
    system->turnOn = turnOn;
    system->turnOff = turnOff;
    system->setBrightness = setBrightness;
    return system;
}
