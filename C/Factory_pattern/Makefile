CC = gcc
CFLAGS = -Wall -Wextra -I.

# Directories
SRC_DIR = .
HUMID_DIR = $(SRC_DIR)/humidity_sensor
LIGHT_DIR = $(SRC_DIR)/light_sensor
FACTORY_DIR = $(SRC_DIR)/sensor_factory

# Source files
SRCS = $(HUMID_DIR)/humidity_sensor.c \
       $(LIGHT_DIR)/light_sensor.c \
       $(FACTORY_DIR)/sensor_factory.c \
       $(SRC_DIR)/main.c


# Object files
OBJS = $(SRCS:.c=.o)

# Output executable
TARGET = Factory_pattern

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(TARGET)
