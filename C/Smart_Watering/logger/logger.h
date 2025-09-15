#ifndef LOGGER_H
#define LOGGER_H

/// Log message priority levels

typedef enum {
    LOG_EMERGENCY,  // Fatal errors, system shutdown
    LOG_ALERT,      // Major failures, memory allocation issues
    LOG_CRITICAL,   // Sensor/pump/LED critical failures
    LOG_ERROR,      // Sensor read/write errors, log file errors
    LOG_WARNING,    // Out-of-range values, repeated invalid input
    LOG_INFO,       // Mode changes, watering events, sensor readings
    LOG_DEBUG,      // Detailed state, variable values, function entry/exit
} logLevel;

// Initializes the logging system
void loggerInit(logLevel level, const char* fileName);

// Function to set the current logging level
void loggerSetLevel(logLevel level);

// Function to closes the logging system
 void loggerClose(void);

// Function to Logs a message with specified level
void loggerLog(logLevel level, const char* fileName, int line, const char* format, ...);

// Convenience macro for logging messages
#define logMessage(level,...) loggerLog(level, __FILE__, __LINE__, __VA_ARGS__)

#endif // LOGGER_H