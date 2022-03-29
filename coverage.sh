#!/usr/bin/env bash

set -e
./build/tests/matrix_tests

lcov -t "build/tests/matrix_test" -o coverage.info -c -d build/tests/CMakeFiles/matrix_tests.dir/
genhtml -o "build/report/" coverage.info
