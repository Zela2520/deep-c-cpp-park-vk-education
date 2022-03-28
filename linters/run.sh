#!/usr/bin/env bash

set -e
set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

print_header "RUN cppcheck"
cppcheck project/matrix --enable=all --inconclusive --error-exitcode=1 -I project/matrix --suppress=missingIncludeSystem

print_header "RUN clang-tidy"
clang-tidy project/matrix/* -- -std=c99 -Iproject/matrix

print_header "RUN cpplint.py"
python3 ./linters/cpplint/cpplint.py --extensions=c,cpp project/matrix/*

print_header "SUCCESS"
