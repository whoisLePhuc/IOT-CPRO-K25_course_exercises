#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "subscriber.h"
#define MAX_SUBSCRIBERS 10

typedef struct Publisher Publisher;

struct Publisher {
    const char* name;
    Subscriber* subscribers[MAX_SUBSCRIBERS];
    int subscriber_count;
    void (*subscribe)(Publisher *self, Subscriber *subscriber); 
    void (*unsubscribe)(Publisher *self, Subscriber *subscriber);
    void (*notify)(Publisher *self, Event *event); 
};

void PublisherInit(Publisher *Publisher, const char *name);

#endif