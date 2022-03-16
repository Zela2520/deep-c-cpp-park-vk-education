cmake_minimum_required(VERSION 3.20)
project(Deep_c)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "--coverage")
set(CMAKE_C_FLAGS "--coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++0x -Wall -Wextra -Werror -Wpedantic")

set(LIB_SOURCE_FILES
        include/task_list.h
        src/list/business_logic.c
        src/list/task_list_memory.c
        src/list/task_list_modify.c
        include/task_info.h
        src/task/get_field.c
        src/task/task_proccesing.c
        src/task/task_inout.c
        src/task/task_memory.c
        src/main.c)

add_library(lib STATIC ${LIB_SOURCE_FILES})

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests.out tests/gtest.cpp)
target_link_libraries(tests.out lib)

target_link_libraries(tests.out ${GTEST_LIBRARIES})
target_link_libraries(tests.out pthread)
