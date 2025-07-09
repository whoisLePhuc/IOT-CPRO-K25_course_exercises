#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <unistd.h>
#include <sys/time.h>
#include "sensors/sensor_factory/sensor_factory.h"
#include "button/button.h"
#include "system/config/config.h"
#include "system/system.h"
#include "pump/pump.h"
#include "LED/led.h"
#include "logger/logger.h"

/* ==================== SYSTEM CONFIGURATION CONSTANTS ==================== */
#define MIN_MOISTURE 46          // Minimum soil moisture threshold (%)
#define MAX_MOISTURE 70          // Maximum soil moisture threshold (%)
#define MAX_WATERING_TIME 3      // Maximum automatic watering duration (seconds)
#define MAX_MANUAL_WATERING_TIME 10  // Maximum manual watering duration (seconds)
#define SENSOR_CHECK_INTERVAL 10 // Sensor data collection interval (seconds)

/* ==================== GLOBAL SYSTEM VARIABLES ==================== */
static Sensor *moisture_sensor = NULL;      // Moisture sensor instance
static Sensor *temperature_sensor = NULL;    // Temperature sensor instance
static System *systemInstance = NULL;       // Main system instance
static LedState ledState = LED_NORMAL;      // Current LED indicator state
static PumpState pumpState = PUMP_OFF;      // Current pump state
static int autoWateringFlag = 0;            // Auto watering activation flag
static int manualWateringFlag = 0;          // Manual watering activation flag

/* ==================== FUNCTION PROTOTYPES ==================== */
System *initSystem(uint8_t minMoisture, uint8_t maxMoisture, uint16_t maxWateringTime, uint16_t sensorCheckInterval);
void Init_All_Sensors();                    // Initialize all sensor modules
void freeAllSystem(System *system);         // Cleanup system resources
void readSensorsData(System *system);       // Read and log sensor data
void autoWateringLogic(System *system);     // Automatic watering control logic
void manualWateringLogic();                 // Manual watering control logic
void setLedState(System *system);           // Update LED indicator states
void setPumpState();                        // Control pump activation/deactivation
int checkButton(System *system);            // Handle user button input
unsigned long millis();                     // Get current time in milliseconds


int main(){
    // Initialize all sensors
    Init_All_Sensors();
    
    // Initialize logger with INFO level and log file
    loggerInit(LOG_INFO, "log_file.txt");

    // Initialize the system with default settings
    System *system = initSystem(MIN_MOISTURE, MAX_MOISTURE, MAX_WATERING_TIME, SENSOR_CHECK_INTERVAL);
    if (system == NULL) {
        logMessage(LOG_EMERGENCY, "System initialization failed. Exiting.");
        exit(1);
    }
    logMessage(LOG_INFO, "System initialized successfully.");
    
    // Display system configuration to user
    printf("========= Watering Settings =========\n");
    printf("Min Moisture: %d%%\n", system->settings->minMoisture);
    printf("Max Moisture: %d%%\n", system->settings->maxMoisture);
    printf("Max Watering Time: %d seconds\n", system->settings->maxWateringTime);
    printf("Sensor Check Interval: %d seconds\n", system->settings->sensorCheckInterval);
    logMessage(LOG_INFO, "System configuration: MinMoisture=%d, MaxMoisture=%d, MaxWateringTime=%d, SensorCheckInterval=%d", system->settings->minMoisture, system->settings->maxMoisture, system->settings->maxWateringTime, system->settings->sensorCheckInterval);

    // Initialize terminal settings for non-blocking button input
    struct termios orig_termios;
    enableRawMode(&orig_termios);
    enableNonBlockingInput();

    // ==================== MAIN CONTROL LOOP ====================
    while(1){
        // Check for user input (exit if 'q' is pressed)
        if(checkButton(system) == 0){
            logMessage(LOG_INFO, "User requested exit. Shutting down main loop.");
            break;
        }
        
        // Execute system logic based on current mode
        logMessage(LOG_DEBUG, "Main loop: currentMode=%d", system->currentMode);
        if(system->currentMode == AUTO_MODE){
            readSensorsData(system);
            autoWateringLogic(system);
            setPumpState();
            setLedState(system);
        }else if(system->currentMode == MANUAL_MODE){
            readSensorsData(system);
            manualWateringLogic();
            setPumpState();
            setLedState(system);
        }

        sleep(1); // Prevent CPU overload and reduce terminal flooding
    }
    
    // ==================== CLEANUP AND EXIT ====================
    freeAllSystem(system);
    disableRawMode(&orig_termios);
    logMessage(LOG_INFO, "System shutdown and resources freed.");
    return 0;
}

// Controls pump activation based on watering flags
void setPumpState(){
    if(autoWateringFlag || manualWateringFlag){
        if (pumpState != PUMP_ON) {
            logMessage(LOG_INFO, "Pump state changed: ON");
        }
        pumpState = PUMP_ON;
        turnPumpOn();
    }else{
        if (pumpState != PUMP_OFF) {
            logMessage(LOG_INFO, "Pump state changed: OFF");
        }
        pumpState = PUMP_OFF;
        turnPumpOff();
    }
}

// Updates LED indicators based on system state and mode
void setLedState(System *system){
    LedState prevLedState = ledState;
    if(system->currentMode == AUTO_MODE){
        // Auto mode LED logic
        if(system->sensorsData.moisture < system->settings->minMoisture && !autoWateringFlag){
            ledState = LED_LOW_MOISTURE_ALERT;
            turnOnLedLowMoisture();
        }else if(autoWateringFlag){
            ledState = LED_WATERING;
            turnOnLedWatering();
        }else{
            ledState = LED_NORMAL;
            turnOnLedNormal();
        }
    }else if(system->currentMode == MANUAL_MODE){
        // Manual mode LED logic
        if(system->sensorsData.moisture < system->settings->minMoisture){
            ledState = LED_LOW_MOISTURE_ALERT;
            turnOnLedLowMoisture();
        }else if(manualWateringFlag){
            ledState = LED_WATERING;
            turnOnLedWatering();
        }else{
            ledState = LED_NORMAL;
            turnOnLedNormal();
        }
    }
    if (ledState != prevLedState) {
        logMessage(LOG_DEBUG, "LED state changed: %d", ledState);
    }
}

// Implements automatic watering logic
void autoWateringLogic(System *system){
    // Check if soil moisture is below minimum threshold
    if(system->sensorsData.moisture < system->settings->minMoisture){
        static unsigned long lastWateringTime = 0;
        
        // Initialize watering timer on first detection
        if(lastWateringTime == 0){
            lastWateringTime = millis();
            logMessage(LOG_INFO, "Auto watering started. Timer initialized.");
        }
        
        unsigned long currentTime = millis();
        
        // Activate pump for specified duration
        if(currentTime - lastWateringTime <= system->settings->maxWateringTime * 1000){
            if (!autoWateringFlag) {
                logMessage(LOG_INFO, "Pump on (auto mode)");
            }
            autoWateringFlag = 1;
        } else {
            // Deactivate pump after maximum watering time
            if (autoWateringFlag) {
                logMessage(LOG_INFO, "Pump off (auto mode)");
            }
            autoWateringFlag = 0;
            lastWateringTime = 0; // Reset timer for next cycle
        }
    }
}

// Implements manual watering logic with time limit
void manualWateringLogic(){
    static unsigned long lastWateringTime = 0;
    
    // Initialize timer when manual watering starts
    if(lastWateringTime == 0){
        lastWateringTime = millis();
        logMessage(LOG_INFO, "Manual watering started. Timer initialized.");
    }
    
    unsigned long currentTime = millis();
    
    // Deactivate pump after maximum manual watering time
    if(currentTime - lastWateringTime >= MAX_MANUAL_WATERING_TIME * 1000){
        if (manualWateringFlag) {
            logMessage(LOG_INFO, "Pump off (manual mode)");
        }
        manualWateringFlag = 0;
        lastWateringTime = 0; // Reset timer
    }
}

// Reads sensor data at specified intervals
void readSensorsData(System *system){
    static unsigned long lastCheckSensorTime = 0;
    
    // Initialize sensor check timer
    if(lastCheckSensorTime == 0){
        lastCheckSensorTime = millis();
    }
    
    unsigned long currentTime = millis();
    
    // Read sensors at specified intervals
    if(currentTime - lastCheckSensorTime >= system->settings->sensorCheckInterval * 1000){
        // Read moisture sensor data
        system->sensorsData.moisture = moisture_sensor->Read_Data(0.0f);
        if (system->sensorsData.moisture < 0.0f || system->sensorsData.moisture > 100.0f) {
            logMessage(LOG_WARNING, "Moisture sensor returned out-of-range value: %.2f%%", system->sensorsData.moisture);
        } else {
            logMessage(LOG_INFO, "Moisture: %.2f%%", system->sensorsData.moisture);
        }
        // Read temperature sensor data
        system->sensorsData.temperature = temperature_sensor->Read_Data(0.0f);
        if (system->sensorsData.temperature < -40.0f || system->sensorsData.temperature > 85.0f) {
            logMessage(LOG_WARNING, "Temperature sensor returned out-of-range value: %.2f Celcius", system->sensorsData.temperature);
        } else {
            logMessage(LOG_INFO, "Temperature: %.2f Celcius", system->sensorsData.temperature);
        }
        lastCheckSensorTime = 0; // Reset timer for next reading
    }
}


// Initializes the main system with specified parameters
System *initSystem(uint8_t minMoisture, uint8_t maxMoisture, uint16_t maxWateringTime, uint16_t sensorCheckInterval){
    // Create system instance if not already created
    if(systemInstance == NULL){
        systemInstance = (System *)malloc(sizeof(System));
    }
    
    // Check memory allocation success
    if (systemInstance == NULL) {
        logMessage(LOG_ALERT, "[SYSTEM]: Memory allocation failed for System" );
        return 0;
    }else{
        logMessage(LOG_INFO, "[SYSTEM]: Create successful" );
    }
    
    // Initialize system with default settings
    systemInstance->currentMode = AUTO_MODE;
    systemInstance->settings = initThreadholdSettings(minMoisture, maxMoisture, maxWateringTime, sensorCheckInterval);
    
    // Check settings initialization
    if (systemInstance->settings == NULL) {
        logMessage(LOG_CRITICAL, "[SYSTEM]: Failed to initialize threshold settings");
        free(systemInstance);
        return 0;
    }

    // Initialize sensor data to zero
    systemInstance->sensorsData.moisture = 0.0f;
    systemInstance->sensorsData.temperature = 0.0f;

    return systemInstance;
}

// Handles user button input for system control
int checkButton(System *system){
    char c;
    int result = read(STDIN_FILENO, &c, 1);  // Non-blocking read
    
    if(result > 0){
        switch(c) {
            case 'm': // Switch to Manual Mode
                autoWateringFlag = 0;
                system->currentMode = MANUAL_MODE;
                logMessage(LOG_INFO, "Manual mode selected by user.");
                return 1;
                
            case 'a': // Switch to Auto Mode
                system->currentMode = AUTO_MODE;
                logMessage(LOG_INFO, "Auto mode selected by user.");
                return 1;
                
            case 'w': // Manual watering (Manual Mode only)
                if(system->currentMode == MANUAL_MODE) {
                    manualWateringFlag = 1;
                    logMessage(LOG_INFO, "Manual watering triggered by user.");
                    logMessage(LOG_INFO, "Pump on (manual mode)");
                } else {
                    logMessage(LOG_WARNING, "Attempted manual watering in auto mode.");
                }
                return 1;
                
            case 'q': // Exit program
                printf("\n[BUTTON]: Exit program\n");
                logMessage(LOG_INFO, "User requested program exit.");
                return 0;
                
            default: // Invalid input
                printf("\n[WARNING]: Invalid. Press 'm', 'a' or 'q'.\n");
                logMessage(LOG_WARNING, "Invalid user input: %c", c);
                return 1;
        }
    }
    return 1; // Continue execution if no input detected
}

// Initializes all sensor modules
void Init_All_Sensors(){
    // Initialize moisture sensor
    if(moisture_sensor == NULL){
        moisture_sensor = Create_Sensor(SENSOR_MOISTURE);
        if(moisture_sensor != NULL){
            moisture_sensor->Init();
        }
    }
    
    // Initialize temperature sensor
    if(temperature_sensor == NULL){
        temperature_sensor = Create_Sensor(SENSOR_TEMPERATURE);
        if(temperature_sensor != NULL){
            temperature_sensor->Init();
        }
    }
}

// Frees all system resources and cleans up memory
void freeAllSystem(System *system) {
    // Free system settings and main system instance
    if (system != NULL) {
        if (system->settings != NULL) {
            free(system->settings);
        }
        free(system);
    }
    
    // Free sensor instances
    if(moisture_sensor != NULL) {
        free(moisture_sensor);
        moisture_sensor = NULL;
    }
    if(temperature_sensor != NULL) {
        free(temperature_sensor);
        temperature_sensor = NULL;
    }
}

// Gets current time in milliseconds
unsigned long millis(){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000000);
}



