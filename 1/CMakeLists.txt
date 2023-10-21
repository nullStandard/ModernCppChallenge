cmake_minimum_required(VERSION 3.9.1)

project(SumOfNaturalsDivisibleBy3And5)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_executable(app main.cpp)