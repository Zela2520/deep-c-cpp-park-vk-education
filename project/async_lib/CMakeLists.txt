cmake_minimum_required(VERSION 3.14)
project(processes_lib)

add_subdirectory(../sync_lib/matrix)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC")
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")

add_library(${PROJECT_NAME} processes/*.c logic/)

target_link_libraries(${PROJECT_NAME} SYNC_MATRIX_LIB_LIBRARIES)

file(GLOB SOURCES *.c)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

add_library(${PROJECT_NAME} SHARED ${SOURCES})

# global scope notification appeared
set(PROCESSES_LIB_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(PROCESSES_LIB_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)
