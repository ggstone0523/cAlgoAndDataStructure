CC = gcc
CFLAGS = -g -o
TARGET = Answer
SRCS = $(wildcard *.c)
HEADERS = $(wildcard *.h)

all: build test clean

build: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(TARGET) $^

test:
	./$(TARGET)

clean:
	rm -rf $(TARGET)

leak: build
	valgrind ./$(TARGET)
	rm -rf $(TARGET)
