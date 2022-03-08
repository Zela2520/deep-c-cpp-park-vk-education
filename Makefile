.PHONY: all build go clean

all: build go

build:
	clang project/src/main.c project/src/task_methods.c -o main.out

go:
	./main.out

clean:
	rm -rf *.o main.out