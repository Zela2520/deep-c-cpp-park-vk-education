#!/usr/bin/env bash

set -e
set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

print_header "RUN cppcheck"
cppcheck sync_lib/**/*.c async_lib/**/*.c main.c --enable=all --inconclusive --error-exitcode=1 -I sync_lib/matrix -I async_lib/matrix -I async_lib/processes --suppress=missingIncludeSystem

print_header "RUN clang-tidy"
clang-tidy sync_lib/**/*.c async_lib/**/*.c main.c-- -std=c99 -Isync_lib -Iasync_lib

print_header "SUCCESS"
