CC = gcc
TARGET = Factorial
SRCS = $(wildcard ./*.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
HEADERS = $(wildcard ./*.h)

all: build test clean

build: $(SRCS) $(HEADERS)
	$(CC) -g -o $(TARGET) $^

test:
	./$(TARGET) 5

clean:
	rm -rf $(TARGET)

leak: build
	valgrind ./$(TARGET) 5
	rm -rf $(TARGET)
