#ifndef PUMP_H
#define PUMP_H

typedef struct {
    void (*on)(void);  // Function to turn the pump on
    void (*off)(void); // Function to turn the pump off
}Pump;

typedef struct{
    void (*turnLedNormal)(void);
    void (*turnLedLowMoistureAlert)(void);
    void (*turnLedWatering)(void);
    void (*turnLedError)(void);
}Led;

void pumpInit(Pump* pump); // Function to initialize the pump
void ledInit(Led* led); // Function to initialize the LED
#endif