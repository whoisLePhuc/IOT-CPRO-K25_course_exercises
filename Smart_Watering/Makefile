CC = gcc
CFLAGS = -Wall -Wextra -I.

# Directories
SRC_DIR = .
SENSORS_DIR = $(SRC_DIR)/sensors
MOISTURE_DIR = $(SENSORS_DIR)/moisture_sensor
TEMP_DIR = $(SENSORS_DIR)/temperature_sensor
FACTORY_DIR = $(SENSORS_DIR)/sensor_factory
BUTTON_DIR = $(SRC_DIR)/button

CONFIG_DIR = $(SRC_DIR)/system/config
LED_DIR = $(SRC_DIR)/LED
PUMP_DIR = $(SRC_DIR)/pump
LOGGER_DIR = $(SRC_DIR)/logger

# Source files
SRCS = $(MOISTURE_DIR)/moisture_sensor.c \
       $(TEMP_DIR)/temperature_sensor.c \
       $(FACTORY_DIR)/sensor_factory.c \
	   $(BUTTON_DIR)/button.c \
	   $(LED_DIR)/led.c \
	   $(LOGGER_DIR)/logger.c \
	   $(PUMP_DIR)/pump.c \
	   $(CONFIG_DIR)/config.c \
       $(SRC_DIR)/main.c


# Object files
OBJS = $(SRCS:.c=.o)

# Output executable
TARGET = main

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(TARGET)
