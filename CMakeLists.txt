cmake_minimum_required(VERSION 3.20)
project(longInteger)

set(CMAKE_CXX_STANDARD 23)

add_executable(longInteger main.cpp)

add_library(BigInt BigInt/src/bigInt.cpp BigInt/Include/bigInt.h)
add_library(tests tests/tests.cpp)

add_subdirectory(logger)

add_subdirectory(tests/googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

target_link_libraries(tests gtest gtest_main)
target_link_libraries(longInteger BigInt mainlogger tests)

