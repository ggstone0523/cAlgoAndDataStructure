CC = gcc
TARGET = Test_AdMatGraph
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

coverage: $(SRCS) $(HEADERS) $(OBJS)
	$(CC) --coverage -c $<
	$(CC) --coverage -o $(TARGET) $(OBJS) $(HEADERS)
	./$(TARGET)
	gcov AdMatGraph.c
	lcov --directory ./ --capture --output-file app.info
	genhtml -o html_report app.info
	rm -rf *.gc* *.o $(TARGET) app.info
