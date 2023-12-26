cmake_minimum_required(VERSION 3.27)
project(Monopoly)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
include_directories(src)

add_executable(Monopoly
        src/main.cpp)
