/**
 * @file sensor.h
 * @brief Smart Watering System - Sensor Interface
 * @description Defines the common interface for all sensor types
 * @author Smart Watering System Team
 * @version 1.0
 * @date 2024
 */

#ifndef SENSOR_H
#define SENSOR_H

/**
 * @brief Generic sensor interface structure
 * @description Defines the common interface that all sensors must implement
 */
typedef struct {
    void(* Init)(void);           // Function pointer to sensor initialization
    float(* Read_Data)(float);    // Function pointer to sensor data reading
}Sensor;

#endif

