TARGET = ./main.out
HDRS_DIR = project/include

SRCS = project/src/main.c \
       project/src/task.c \
       project/src/task_list.c

.PHONY: all build ran rebuild clean

all: build run

$(TARGET): $(SRCS) 
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TARGET) $(CFLAGS) $(SRCS)

build: $(TARGET)

run:
	$(TARGET)

rebuild: clean build

clean:
	rm -rf $(TARGET)