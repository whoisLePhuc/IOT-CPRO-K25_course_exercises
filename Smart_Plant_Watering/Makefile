CC = gcc

CFLAGS = -Wall -Wextra -I.

# Main folder
ACTUATORS_DIR = ./actuators
CONFIG_DIR = ./config
SENSORS_DIR = ./sensors
SYSTEM_DIR = ./system

# Sub folder
FACTORY_DIR = $(SENSORS_DIR)/sensor_factory
MOISTURE_DIR = $(SENSORS_DIR)/moisture
TEMPERATURE_DIR = $(SENSORS_DIR)/temperature

# Source files
SRCS = \
$(ACTUATORS_DIR)/actuators.c \
$(CONFIG_DIR)/config.c \
$(FACTORY_DIR)/sensor_factory.c \
$(MOISTURE_DIR)/moisture.c \
$(TEMPERATURE_DIR)/temperature.c \
$(SYSTEM_DIR)/system.c \
./main.c

# Object files
OBJS = $(SRCS:.c=.o)

# Output
TARGET = main

# Build
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
