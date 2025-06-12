#ifndef LIGHT_SYSTEM_H
#define LIGHT_SYSTEM_H

typedef struct{
    void(*turnOn)(void);
    void(*turnOff)(void);
    void(*setBrightness)(int brightness);
}LightSystem;

LightSystem* createLightSystem();

#endif