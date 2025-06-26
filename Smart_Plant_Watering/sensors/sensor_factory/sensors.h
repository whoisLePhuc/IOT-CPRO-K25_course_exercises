#ifndef SENSORS_H
#define SENSORS_H

// Sensor structure
typedef struct{
    void (*init)(void); // Function to initialize sensor
    float (*readData)(void); // Function to read data from sensor
}Sensor;

#endif