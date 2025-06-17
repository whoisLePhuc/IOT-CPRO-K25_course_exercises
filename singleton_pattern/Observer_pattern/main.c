#include <stdio.h>
#include "inc/publisher.h"
#include "inc/subscriber.h"
#include "inc/sensors/Door_sensor.h"
#include "inc/sensors/Smoke_sensor.h"

int main(){
    // Create Subscribers
    Subscriber mobileApp, alarmSystem, logger, hvacSystem;
    SubscriberInit(&mobileApp, "MobileApp", MobileAppUpdate);
    SubscriberInit(&alarmSystem, "AlarmSystem", AlarmUpdate);
    SubscriberInit(&logger, "Logger", LoggerUpdate);
    SubscriberInit(&hvacSystem, "HvacSystem", HvacSystemUpdate);

    // Create Publisher
    DoorSensor frontDoor, garaDoor; 
    DoorSensorInit(&frontDoor, "Front Door");
    DoorSensorInit(&garaDoor, "Gara Door");
    SmokeSensor kitchen; 
    SmokeSensorInit(&kitchen, "kitchen");

    // Regist Subscriber to Publisher
    frontDoor.Base.subscribe(&frontDoor.Base, &mobileApp);
    frontDoor.Base.subscribe(&frontDoor.Base, &alarmSystem);
    frontDoor.Base.subscribe(&frontDoor.Base, &logger);

    garaDoor.Base.subscribe(&garaDoor.Base, &mobileApp);
    garaDoor.Base.subscribe(&garaDoor.Base, &alarmSystem);
    garaDoor.Base.subscribe(&garaDoor.Base, &logger);

    kitchen.Base.subscribe(&kitchen.Base, &mobileApp);
    kitchen.Base.subscribe(&kitchen.Base, &alarmSystem);
    kitchen.Base.subscribe(&kitchen.Base, &hvacSystem);
    kitchen.Base.subscribe(&kitchen.Base, &logger);

    // Simulate Events
    DoorSensorOpen(&frontDoor, 10000);
    DoorSensorOpen(&garaDoor, 10000);
    SmokeSensorDetect(&kitchen, 10000);

    // Unsubscribe 
    kitchen.Base.unsubscribe(&kitchen.Base, &mobileApp);
    kitchen.Base.unsubscribe(&kitchen.Base, &logger);
    
    // Simulate Events
    DoorSensorOpen(&frontDoor, 10000);
    DoorSensorOpen(&garaDoor, 10000);
    SmokeSensorDetect(&kitchen, 10000);
    return 0;
}