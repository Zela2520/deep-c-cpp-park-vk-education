#!/usr/bin/env bash

set -e
./build/tests/matrix_tests

lcov -t "build/tests/matrix_tests" -o coverage.info -c -d build/tests/CMakeFiles/matrix_tests.dir/
genhtml -o "build/report/" coverage.info

#./build/tests/async_matrix_tests
#
#lcov -t "build/tests/async_matrix_tests" -o coverage.info -c -d build/tests/CMakeFiles/async_matrix_tests.dir/
#genhtml -o "build/report_2/" coverage.info