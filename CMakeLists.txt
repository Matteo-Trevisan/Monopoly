cmake_minimum_required(VERSION 3.27)
project(Monopoly)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
include_directories(src)

add_executable(Monopoly
        src/main.cpp)

add_library(Space
        src/Space.cpp
        include/space.h
        src/Normal_Space.cpp
        include/Normal_Space.h
        include/Space_Data.h
        src/Angular_Space.cpp
        include/Angular_Space.h
)

target_link_libraries(Monopoly Space)
