TARGET = build/tests/matrix_test

.PHONY: all build rebuild check test memtest covtest clean dock stop

all: clean check build test memtest covtest

dock:
	docker run -it -v "/Users/sugarbearzelagmail.com/Documents/IT/Deep_C/:/TPark" --rm zela28/deep_c

stop:
	docker stop zela28/deep_c

build:
	./build.sh

rebuild: clean build

check:
	./linters/run.sh

test:
	./build.sh
	./${TARGET}

memtest:
	./build.sh
	./tests/memtest.sh ./${TARGET}

covtest:
	./build.sh
	./coverage.sh

clean:
	rm -rf build valgrind.log
