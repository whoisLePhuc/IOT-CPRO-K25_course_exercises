#include <stdio.h>
#include "../inc/subscriber.h"

void SubscriberInit(Subscriber *subscriber, const char *name, void (*update)(Subscriber *, Event *)) {
    subscriber->name = name;
    subscriber->update = update;
}

void MobileAppUpdate(Subscriber *self, Event *event) {
    printf("[%s] Notification: Event %d at %s, level=%d\n",
           self->name, event->type, event->location, event->level);
}

void AlarmUpdate(Subscriber *self, Event *event){
        printf("[%s] Alarm triggered at %s\n",
               self->name, event->location);
}

void LoggerUpdate(Subscriber *self, Event *event) {
    printf("[%s] Logged event %d at %s, level=%d\n",
           self->name, event->type, event->location, event->level);
}

void HvacSystemUpdate(Subscriber *self, Event *event) {
    printf("[%s] HVAC adjusted settings for event %d at %s, level=%d\n",
            self->name, event->type, event->location, event->level);

}
