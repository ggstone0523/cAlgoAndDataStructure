CC = gcc
TARGET = Answer
SRCS = $(wildcard ./*.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
HEADERS = $(wildcard ./*.h)

all: build test clean

build: $(SRCS) $(HEADERS)
	$(CC) -g -o $(TARGET) $^

test:
	./$(TARGET)

clean:
	rm -rf $(TARGET)

leak: build
	valgrind ./$(TARGET)
	rm -rf $(TARGET)
