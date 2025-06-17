#ifndef EVENT_H
#define EVENT_H

typedef enum{
    EVT_DOOR_OPEN,
    EVT_DOOR_CLOSE,
    EVT_SMOKE_DETECTED,
    EVT_TEMPERATURE_HIGH,
    EVT_TEMPERATURE_LOW,
    EVT_HUMIDITY_HIGH,
    EVT_HUMIDITY_LOW,
    EVT_MOTION_DETECTED
} Eventype;

typedef struct {
    Eventype type;
    const char* location;
    int level;
    unsigned long time;
} Event;

#endif