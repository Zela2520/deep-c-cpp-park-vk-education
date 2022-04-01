#TARGET = build/tests/sync_matrix_tests
TARGET = build/tests/matrix_tests
ASYNC_TARGET = build/tests/async_matrix_tests

#.PHONY: all build rebuild check test test_2 memtest memtest_2 covtest clean
#
#all: clean check build test memtest covtest

.PHONY: all build rebuild check test memtest covtest clean

all: clean check build test memtest covtest

build:
	./build.sh

rebuild: clean build

check:
	./linters/run.sh

test:
	./build.sh
	./${TARGET}
	#./${ASYNC_TARGET}

memtest:
	./build.sh
	./tests/memtest.sh ./${TARGET}
	#./tests/memtest.sh ./${ASYNC_TARGET}

covtest:
	./build.sh
	./coverage.sh

clean:
	rm -rf build valgrind.log
