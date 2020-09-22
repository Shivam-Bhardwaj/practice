cmake_minimum_required(VERSION 3.15)
project(cpp_practice)

set(CMAKE_CXX_STANDARD 11)

#add_executable(run exp.cpp)
link_libraries(pthread)
add_executable(run cpp_files/threads_try.cpp)
