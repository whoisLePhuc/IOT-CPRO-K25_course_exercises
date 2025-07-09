#ifndef PUMP_H
#define PUMP_H

// Pump operation states
typedef enum{
    PUMP_OFF,  
    PUMP_ON    
}PumpState;

// Function to activates the water pump
void turnPumpOn();

// Function to deactivates the water pump
void turnPumpOff();

#endif