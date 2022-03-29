cmake_minimum_required(VERSION 3.14)
project(business_logic_lib)

add_subdirectory(../matrix build)

# compilation options so that it constructs additional instructions that will later collect coverage information
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC")
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC")

file(GLOB SOURCES *.c)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC matrix_lib)

# global scope notification appeared
set(BUSINESS_LIB_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(BUSINESS_LIB_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)
