TARGET = ./main.out
HDRS_DIR = project/include

SRCS = project/src/main.c \
       project/src/list/business_logic.c \
       project/src/list/task_list_memory.c \
       project/src/list/task_list_modify.c \
       project/src/task/task_proccesing.c \
       project/src/task/task_memory.c \
       project/src/task/task_inout.c

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