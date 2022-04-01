#!/usr/bin/env bash

set -e
./build/tests/sync_tests

lcov -t "build/tests/sync_tests" -o coverage.info -c -d build/tests/CMakeFiles/sync_tests.dir/
genhtml -o "build/report/" coverage.info

set -e
./build/tests/async_tests

lcov -t "build/tests/async_tests" -o coverage.info -c -d build/tests/CMakeFiles/async_tests.dir/
genhtml -o "build/report_2/" coverage.info