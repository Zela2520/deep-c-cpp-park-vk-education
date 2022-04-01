cmake_minimum_required(VERSION 3.14)
project(asynchronous_lib)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC")
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")

add_library(async_matrix_lib SHARED matrix/matrix.c
        processes/processes.c
        logic/async_business_logic.c
        logic/async_calculations.c)

target_include_directories(async_matrix_lib PUBLIC matrix)
target_include_directories(async_matrix_lib PUBLIC processes)

add_executable(${PROJECT_NAME} SHARED main.c)

target_link_libraries(${PROJECT_NAME} async_matrix_lib)

set(ASYNC_MATRIX_LIB_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
