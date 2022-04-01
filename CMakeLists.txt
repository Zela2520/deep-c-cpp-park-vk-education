cmake_minimum_required(VERSION 3.14)
project(matrix)

add_subdirectory(sync_lib)
add_subdirectory(async_lib)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")

add_subdirectory(tests)
