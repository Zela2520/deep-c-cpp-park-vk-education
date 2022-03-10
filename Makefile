TARGET = ./main.out
HDRS_DIR = project/include

SRCS = project/src_2/main.c \
       project/src_2/list/business_logic.c \
       project/src_2/list/task_list.c \
       project/src_2/task/task_proccesing.c \
       project/src_2/task/task_memory.c \
       project/src_2/task/task_inout.c

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