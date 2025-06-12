CC = gcc
CFLAGS = -Wall -Wextra -I.

# Directories
SRC_DIR = .
DECO_DIR = $(SRC_DIR)/decorators
BASE_DIR = $(SRC_DIR)/RawUartChannel

# Source files
SRCS = 	$(BASE_DIR)/RawUartChannel.c \
		$(DECO_DIR)/compression_decorator.c \
		$(DECO_DIR)/encryption_decorator.c \
		$(DECO_DIR)/logging_decorator.c \
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
