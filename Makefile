TARGET = ./main.out
HDRS_DIR = include

SRCS = src/main.c \
	src/list/business_logic.c \
	src/list/task_list_memory.c \
	src/list/task_list_modify.c \
	src/task/task_proccesing.c \
	src/task/task_memory.c \
	src/task/get_field.c \
	src/task/task_inout.c

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