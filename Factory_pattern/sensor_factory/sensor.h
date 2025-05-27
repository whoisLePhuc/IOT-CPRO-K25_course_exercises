#ifndef SENSOR_H
#define SENSOR_H

typedef struct {
    void(* Init)(void); // Function to initialize the sensor
    float(* Read_Data)(float);   // Function to read data from the sensor
}Sensor;

#endif

