cmake_minimum_required(VERSION 3.14)
project(matrix_tests)

# add flags at compile time and add flags at the linking stage
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC -pthread")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

enable_testing()
# find the GTest library, if we can’t find it, then we will fall on this line
find_package(GTest REQUIRED)

# added all tests to the sources
file(GLOB SOURCES *.cpp)
# from sources we collect an executable file for tests
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${MATRIX_LIB_INCLUDE_DIRS} ${BUSINESS_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${MATRIX_LIB_LIBRARIES} ${BUSINESS_LIB_LIBRARIES} GTest::GTest GTest::Main)
