CC = gcc
CFLAGS = -Wall -Wextra -I.

# Directories
SRC_DIR = .

# Source files
SRCS = $(SRC_DIR)/main.c


# Object files
OBJS = $(SRCS:.c=.o)

# Output executable
TARGET = singleton_pattern

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(TARGET)
