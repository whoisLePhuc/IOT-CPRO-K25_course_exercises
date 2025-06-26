#ifndef SYSTEM_H
#define SYSTEM_H

#include"config/config.h"
#include"sensors/sensor_factory/sensor_factory.h"

typedef struct System System;

struct System{
    SystemMode currentMode;
    LedState ledState;
    PumpState pumpState;
    WateringSettings settings;
    SensorsData sensorsData;
    void (*setMode)(struct System *self, SystemMode newMode);
    float (*readSensorsData)(struct System *self, sensorType type);
    void (*updateSensorData)(struct System *self);
    void (*setLedState)(struct System *self);
    void (*setPumpState)(struct System *self);
    void (*clickAutoButton)(struct System *self);
    void (*clickManualButton)(struct System *self);
};

System *createSystem(WateringSettings settings, SensorsData sensorsData);

#endif