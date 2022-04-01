#!/usr/bin/env bash

set -e
./build/tests/sync_tests

lcov -t "build/tests/sync_tests" "build/tests/async_tests" -o coverage.info -c -d build/tests/CMakeFiles/sync_tests.dir/ build/tests/CMakeFiles/async_tests.dir/
genhtml -o "build/report/" coverage.info

#./build/tests/async_matrix_tests

#lcov -t "build/tests/async_matrix_tests" -o coverage.info -c -d build/tests/CMakeFiles/async_matrix_tests.dir/
#genhtml -o "build/report_2/" coverage.info