TARGET = ./main.out
HDRS_DIR = project/include

SRCS = project/src/main.c \
       project/src/task_inout.c \
       project/src/task_list.c \
       project/src/proccesing_input.c \
       project/src/task_alloc.c

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