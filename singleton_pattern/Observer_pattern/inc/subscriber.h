#ifndef SENSOR_H
#define SENSOR_H

#include "event.h"
typedef struct Subscriber Subscriber;

struct Subscriber{
    const char* name;
    void (*update)(Subscriber* self, Event *event);
};

void MobileAppUpdate(Subscriber *self, Event *event);
void AlarmUpdate(Subscriber *self, Event *event);
void LoggerUpdate(Subscriber *self, Event *event);
void HvacSystemUpdate(Subscriber *self, Event *event);
void SubscriberInit(Subscriber *subscriber, const char *name, void (*update)(Subscriber *, Event *));

#endif