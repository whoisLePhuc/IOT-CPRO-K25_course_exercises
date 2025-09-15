#include <stdio.h>
#include "inc/publisher.h"

static void Subscribe(Publisher *self, Subscriber *subscriber) {
    if (self->subscriber_count < MAX_SUBSCRIBERS) {
        self->subscribers[self->subscriber_count++] = subscriber;
        printf("Subscriber [%s] subscribed to publisher %s\n", subscriber->name, self->name);
    } else {
        printf("Cannot subscribe: maximum subscribers reached for publisher %s\n", self->name);
    }
}

static void Unsubscribe(Publisher *self, Subscriber *subscriber) {
    for (int i = 0; i < self->subscriber_count; i++) {
        if (self->subscribers[i] == subscriber) {
            self->subscribers[i] = self->subscribers[--self->subscriber_count];
            printf("\nSubscriber [%s] unsubscribed from publisher [%s] at \n", 
                subscriber->name, self->name);
            return;
        }
    }
    printf("Subscriber [%s] not found in publisher %s\n", subscriber->name, self->name);
}

static void NotifySubscribers(Publisher *self, Event *event) {
    printf("\n[%s] Trigger event!\n", self->name);
    for(int i=0; i < self->subscriber_count; ++i){
        self->subscribers[i]->update(self->subscribers[i], event);
    }
}

void PublisherInit(Publisher* publisher, const char* name){
    publisher->name = name;
    publisher->subscriber_count = 0;
    publisher->subscribe = Subscribe;
    publisher->unsubscribe = Unsubscribe;
    publisher->notify = NotifySubscribers;   
}