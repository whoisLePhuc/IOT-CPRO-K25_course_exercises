#ifndef LED_H
#define LED_H

// LED indicator states
 typedef enum{
    LED_NORMAL,              
    LED_WATERING,            
    LED_LOW_MOISTURE_ALERT,  
    LED_ERROR                
}LedState;

// Function to activates normal operation LED indicator
void turnOnLedNormal();

//Function to activates watering LED indicator
void turnOnLedWatering();

// Function to activates low moisture alert LED indicator
void turnOnLedLowMoisture();

// FUnction to activates error LED indicator
void turnOnLedError();

#endif // LED_H