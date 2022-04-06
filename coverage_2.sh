#!/usr/bin/env bash

set -e
./build/tests/async_tests

lcov -t build/tests/async_tests -o coverage.info -c -d build/async_lib/
genhtml -o build/report_2/ coverage.info