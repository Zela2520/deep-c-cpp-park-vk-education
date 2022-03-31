cmake_minimum_required(VERSION 3.14)
project(calculation_lib)

add_subdirectory(matrix)
add_subdirectory(processes)

# compilation options so that it constructs additional instructions that will later collect coverage information
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC")
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC")

file(GLOB SOURCES *.c)
file(GLOB INCLUDE_DIRS matrix processes)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${MATRIX_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${MATRIX_LIB_LIBRARIES})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROCESSES_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROCESSES_LIB_LIBRARIES})

# global scope notification appeared
set(CALCULATION_LIB_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(CALCULATION_LIB_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)
