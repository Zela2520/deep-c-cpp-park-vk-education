cmake_minimum_required(VERSION 3.20)
project(Deep_c)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

add_library(lib STATIC src/list/business_logic.c
            src/list/task_list_memory.c
            src/list/task_list_modify.c
            src/task/get_field.c
            src/task/task_proccesing.c
            src/task/task_inout.c
            src/task/task_memory.c)

target_include_directories(lib PUBLIC include)

add_executable(hw-1 src/main.c)
target_link_libraries(hw-1 lib)

enable_testing()

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(test.out tests/gtest.cpp)
target_link_libraries(test.out lib ${GTEST_LIBRARIES} Threads::Threads)
