CC = gcc
CFLAGS = -Wall -Wextra -I.

# Directories
SRC_DIR = .
FACADE_DIR = $(SRC_DIR)/smart_home_facade
HVAC_DIR = $(SRC_DIR)/hvac
LIGHT_DIR = $(SRC_DIR)/light
SECURITY_DIR = $(SRC_DIR)/security

# Source files
SRCS = $(FACADE_DIR)/smart_home_facade.c \
       $(HVAC_DIR)/hvac.c \
       $(LIGHT_DIR)/light.c \
       $(SECURITY_DIR)/security.c \
       $(SRC_DIR)/main.c


# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Output executable
TARGET = smartHome

# Build rules
all: $(OBJ_DIR) $(TARGET)

$(OBJ_DIR):
       mkdir -p $(OBJ_DIR)/smart_home_facade $(OBJ_DIR)/hvac $(OBJ_DIR)/light $(OBJ_DIR)/security 

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
       $(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
