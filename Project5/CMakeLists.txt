cmake_minimum_required(VERSION 3.1)
project(Project5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Project5.cpp)
add_executable(Project5 ${SOURCE_FILES} Project5.cpp)