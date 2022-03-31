cmake_minimum_required(VERSION 3.14)
project(matrix)

add_subdirectory(project)

message("CALCULATION_LIB_INCLUDE_DIRS = ${CALCULATION_LIB_INCLUDE_DIRS}")
message("CALCULATION_LIB_LIBRARIES = ${CALCULATION_LIB_LIBRARIES}")

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC")

file(GLOB SOURCES *.c)
file(GLOB INCLUDE_DIRS matrix processes)

add_executable(${PROJECT_NAME} project/sync_lib/logic/business_logic.c main.c)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")

target_include_directories(${PROJECT_NAME} PUBLIC ${CALCULATION_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${CALCULATION_LIB_LIBRARIES})

add_subdirectory(tests)
