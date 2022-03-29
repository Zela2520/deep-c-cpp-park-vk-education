#!/usr/bin/env bash

set -e
set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

print_header "RUN cppcheck"
cppcheck main.c project/**/*.c --enable=all --inconclusive --error-exitcode=1 -I project/matrix -I project/business_logic --suppress=missingIncludeSystem

print_header "SUCCESS"
