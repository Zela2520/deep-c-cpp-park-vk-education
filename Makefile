TARGET = build/tests/sync_tests
ASYNC_TARGET = build/tests/async_tests

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
	./${ASYNC_TARGET}

memtest:
	./build.sh
	./tests/memtest.sh ./${TARGET}
	./tests/memtest.sh ./${ASYNC_TARGET}

covtest:
	./build.sh
	./coverage.sh ${TARGET}
	./coverage_2.sh ${ASYNC_TARGET}

clean:
	rm -rf build valgrind.log coverage.info
