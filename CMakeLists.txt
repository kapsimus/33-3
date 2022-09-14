cmake_minimum_required(VERSION 3.22)
project(33_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(33_3 src/main.cpp include/Registry.h)
target_include_directories(33_3 PUBLIC include)