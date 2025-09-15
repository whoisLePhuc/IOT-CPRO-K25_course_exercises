CC = gcc
CFLAGS = -Wall -Wextra -I.

# Directories
SRC_DIR = .
SOURCE_DIR = $(SRC_DIR)/src


# Source files
SRCS = $(SOURCE_DIR)/MusicPlayer.c \
       $(SOURCE_DIR)/PauseState.c \
       $(SOURCE_DIR)/PlayingState.c \
       $(SOURCE_DIR)/StopState.c \
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

