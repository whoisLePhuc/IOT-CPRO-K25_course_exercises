#include<stdio.h>
#include<stdlib.h>
#include "security.h"

static void activateSercuritySystem() {
    printf("Turning on the security alarm.\n");
}

static void deactivateSercuritySystem(){
    printf("Turning off the security alarm.\n");
}

static void monitorDoorSensors() {
    printf("Monitoring door sensors.\n");
}

static void monitorMovementSensors() {
    printf("Monitoring movement sensors.\n");
}

// Function to create an instance of SercuritySystem
SercuritySystem* createSercuritySystem(){
    SercuritySystem* system = (SercuritySystem*)malloc(sizeof(SercuritySystem));
    system->activateSercuritySystem = activateSercuritySystem;
    system->deactivateSercuritySystem = deactivateSercuritySystem;
    system->monitorDoorSensors = monitorDoorSensors;
    system->monitorMovementSensors = monitorMovementSensors;
    return system;
}