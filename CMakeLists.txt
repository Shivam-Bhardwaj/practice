cmake_minimum_required(VERSION 3.15)
project(cpp_practice)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

#add_executable(run exp.cpp)
add_executable(run scratch.cpp )
