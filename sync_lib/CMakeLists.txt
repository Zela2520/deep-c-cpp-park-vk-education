cmake_minimum_required(VERSION 3.14)
project(sequential_lib)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC")
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")

add_library(sync_matrix_lib STATIC matrix/matrix.c
        logic/business_logic.c
        logic/calculations.c)

target_include_directories(sync_matrix_lib PUBLIC matrix)

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} sync_matrix_lib)

set(SYNC_MATRIX_LIB_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)

add_subdirectory(tests)
