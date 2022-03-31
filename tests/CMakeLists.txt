cmake_minimum_required(VERSION 3.14)
project(matrix_tests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC -pthread")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

enable_testing()
find_package(GTest REQUIRED)

file(GLOB SOURCES *.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CALCULATION_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${CALCULATION_LIB_LIBRARIES} GTest::GTest GTest::Main)
