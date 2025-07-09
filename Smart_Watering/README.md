# Smart Watering System

## Overview

The Smart Watering System is an automated plant watering solution that monitors soil moisture and temperature to provide intelligent irrigation control. The system operates in two modes: **Automatic Mode** for hands-free operation and **Manual Mode** for user-controlled watering.

## Features

### 🌱 **Dual Mode Operation**
- **Auto Mode**: Automatically waters plants when soil moisture drops below threshold
- **Manual Mode**: User-controlled watering with safety time limits

### 📊 **Real-time Monitoring**
- Continuous soil moisture monitoring
- Ambient temperature tracking
- Configurable sensor reading intervals

### 🛡️ **Safety Features**
- Maximum watering time limits to prevent overwatering
- Configurable moisture thresholds
- Comprehensive error logging and monitoring

### 💡 **Visual Feedback**
- LED indicators for system status
- Real-time status updates
- Error condition alerts

### 📝 **Comprehensive Logging**
- Event logging with multiple priority levels
- Sensor data recording
- System operation tracking

## System Architecture

```
Smart Watering System
├── Main Controller (main.c)
├── System Management
│   ├── System State (system.h)
│   └── Configuration (config.h)
├── Sensor System
│   ├── Sensor Factory (sensor_factory.h)
│   ├── Moisture Sensor
│   └── Temperature Sensor
├── Control Interfaces
│   ├── Pump Control (pump.h)
│   ├── LED Indicators (led.h)
│   └── Button Input (button.h)
└── Logging System (logger.h)
```

## Key Components

### 1. **Main Controller** (`main.c`)
- Central control loop
- Mode switching logic
- System initialization and cleanup

### 2. **Sensor System**
- **Factory Pattern**: Unified sensor creation interface
- **Moisture Sensor**: Soil humidity measurement
- **Temperature Sensor**: Ambient temperature monitoring

### 3. **Control Interfaces**
- **Pump Control**: Water delivery management
- **LED Indicators**: Visual status feedback
- **Button Input**: User interaction handling

### 4. **Configuration Management**
- Configurable moisture thresholds
- Adjustable watering durations
- Customizable sensor intervals

## System Configuration

### Default Settings
- **Minimum Moisture**: 46%
- **Maximum Moisture**: 70%
- **Auto Watering Time**: 3 seconds
- **Manual Watering Time**: 10 seconds
- **Sensor Check Interval**: 10 seconds

### LED Status Indicators
- **Normal**: System operating normally
- **Watering**: Pump is currently active
- **Low Moisture Alert**: Soil moisture below threshold
- **Error**: System malfunction detected

## User Interface

### Button Controls
- **'a'**: Switch to Auto Mode
- **'m'**: Switch to Manual Mode
- **'w'**: Manual watering (Manual Mode only)
- **'q'**: Exit system

### System Feedback
- Real-time sensor data display
- LED status indicators
- Comprehensive logging to `log_file.txt`

## Operating Modes

### Auto Mode
1. **Continuous Monitoring**: Sensors read data at specified intervals
2. **Threshold Detection**: Monitors soil moisture levels
3. **Automatic Watering**: Activates pump when moisture drops below minimum
4. **Time Limiting**: Limits watering duration to prevent overwatering
5. **Status Updates**: Provides visual and logged feedback

### Manual Mode
1. **User Control**: Manual activation via button press
2. **Time Safety**: Maximum 10-second watering duration
3. **Sensor Monitoring**: Continues to monitor and log sensor data
4. **Visual Feedback**: LED indicators show system status

## Safety Features

### Overwatering Prevention
- Configurable maximum watering times
- Moisture threshold monitoring
- Automatic pump deactivation

### Error Handling
- Memory allocation checks
- Sensor initialization validation
- Comprehensive error logging

### Resource Management
- Proper memory cleanup on exit
- Terminal settings restoration
- Sensor resource deallocation

## Development Features

### Code Quality
- **Modular Design**: Clean separation of concerns
- **Factory Pattern**: Extensible sensor system
- **Comprehensive Documentation**: Professional commenting throughout
- **Error Handling**: Robust error checking and logging

### Extensibility
- Easy addition of new sensor types
- Configurable system parameters
- Modular component architecture

## Building and Running

### Prerequisites
- GCC compiler
- Make build system
- Linux/Unix environment

### Build Instructions
```bash
make clean
make
```

### Running the System
```bash
./main
```

### System Output
```
========= Watering Settings =========
Min Moisture: 46%
Max Moisture: 70%
Max Watering Time: 3 seconds
Sensor Check Interval: 10 seconds
```

## Logging System

The system provides comprehensive logging with multiple priority levels:

- **LOG_EMERGENCY**: System is unusable
- **LOG_ALERT**: Action must be taken immediately
- **LOG_CRITICAL**: Critical conditions
- **LOG_ERROR**: Error conditions
- **LOG_WARNING**: Warning conditions
- **LOG_INFO**: Informational messages
- **LOG_DEBUG**: Debug-level messages

All system events are logged to `log_file.txt` with timestamps and source information.

## Technical Specifications

### Hardware Requirements
- Moisture sensor (simulated in current implementation)
- Temperature sensor (simulated in current implementation)
- Water pump control interface
- LED indicator system
- User input interface

### Software Requirements
- C standard library
- POSIX system calls
- Terminal control functions

### Performance Characteristics
- **Response Time**: < 1 second for user input
- **Sensor Reading**: Every 10 seconds (configurable)
- **Watering Duration**: 3-10 seconds (configurable)
- **Memory Usage**: Minimal footprint with proper cleanup

## Future Enhancements

### Planned Features
- **Web Interface**: Remote monitoring and control
- **Mobile App**: Smartphone integration
- **Weather Integration**: External weather data consideration
- **Multiple Zones**: Support for multiple watering areas
- **Advanced Sensors**: pH, light, and humidity sensors

### Potential Improvements
- **Machine Learning**: Predictive watering algorithms
- **Cloud Integration**: Remote data storage and analysis
- **Energy Optimization**: Solar power integration
- **Advanced Scheduling**: Time-based watering patterns

## Contributing

This project follows professional coding standards with:
- Comprehensive documentation
- Modular architecture
- Error handling
- Memory management
- Consistent coding style

## License

This project is developed for educational and demonstration purposes.

## Support

For technical support or questions about the Smart Watering System, please refer to the comprehensive code documentation and logging system for detailed information about system operation and troubleshooting.