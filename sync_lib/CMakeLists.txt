cmake_minimum_required(VERSION 3.14)
project(sequential_lib)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC")
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")

# create a static library
add_library(sync_matrix_lib STATIC matrix/matrix.c
        logic/business_logic.c
        logic/calculations.c)

# passing the paths for the source files of the library
target_include_directories(sync_matrix_lib PUBLIC matrix)

# create a project
add_executable(${PROJECT_NAME} main.c)

# building a project with a static library
target_link_libraries(${PROJECT_NAME} sync_matrix_lib)

# transfer the static library to a higher level
set(SYNC_MATRIX_LIB_LIBRARIES sync_matrix_lib PARENT_SCOPE)
