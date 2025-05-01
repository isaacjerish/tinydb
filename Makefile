CC      := gcc
CFLAGS  := -Wall -Wextra -Wpedantic -std=c11 -g
TARGET  := tinydb
SRC     := main.c

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o