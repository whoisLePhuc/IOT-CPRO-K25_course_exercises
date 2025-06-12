#ifndef SMART_HOME_FACADE_H
#define SMART_HOME_FACADE_H
#include "../light/light.h"
#include "../security/security.h"  
#include "../hvac/hvac.h"

typedef struct{
    SercuritySystem* security;
    LightSystem* light;
    HvacSystem* hvac;
}SmartHomeFacade;

SmartHomeFacade* createSmartHomeFacade();
void activateMorningRoutine(SmartHomeFacade* facade);
void activateAwayMode(SmartHomeFacade* facade);
void setMovieNightScene(SmartHomeFacade* facade);

#endif