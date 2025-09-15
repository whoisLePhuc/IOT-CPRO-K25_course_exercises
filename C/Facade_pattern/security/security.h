#ifndef SERCURITY_SYSTEM_H
#define SERCURITY_SYSTEM_H

typedef struct{
    void(*activateSercuritySystem)(void);
    void(*deactivateSercuritySystem)(void);
    void(*monitorDoorSensors)(void);
    void(*monitorMovementSensors)(void);
}SercuritySystem;

SercuritySystem* createSercuritySystem();

#endif