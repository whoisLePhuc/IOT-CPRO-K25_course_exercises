CC = gcc
CFLAGS = -Wall -Wextra -I.

# Directories
SRC_DIR = .
OBJ_DIR = $(SRC_DIR)/src
SENSOR_DIR = $(OBJ_DIR)/sensors


# Source files
SRCS = $(SENSOR_DIR)/Door_sensor.c \
	   $(SENSOR_DIR)/Smoke_sensor.c \
	   $(SENSOR_DIR)/AHT30_sensor.c \
	   $(SENSOR_DIR)/Motion_sensor.c \
       $(OBJ_DIR)/publisher.c \
	   $(OBJ_DIR)/subscriber.c \
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
