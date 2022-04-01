cmake_minimum_required(VERSION 3.14)
project(asynchronous_lib)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC")
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")

# create a shared library
add_library(async_matrix_lib STATIC matrix/matrix.c
        processes/processes.c
        logic/async_business_logic.c
        logic/async_calculations.c)

# passing the paths for the source files of the library
target_include_directories(async_matrix_lib PUBLIC matrix)
target_include_directories(async_matrix_lib PUBLIC processes)

# create a project
add_executable(${PROJECT_NAME} main.c)

# building a project with a shared library
target_link_libraries(${PROJECT_NAME} async_matrix_lib)

# transfer the shared library to a higher level
set(ASYNC_MATRIX_LIB_LIBRARIES async_matrix_lib PARENT_SCOPE)
