#!/usr/bin/env bash

set -e
./build/tests/main_test

lcov -t "build/tests/matrix_test" -o coverage.info -c -d build/project/CMakeFiles/matrix_tests.dir/
genhtml -o "build/report/" coverage.info
