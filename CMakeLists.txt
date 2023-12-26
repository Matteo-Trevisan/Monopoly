cmake_minimum_required(VERSION 3.00 FATAL_ERROR)
project(Monopoly)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
include_directories(src)

add_executable(Monopoly
        src/main.cpp)

add_library(Space
        include/Space/Space.h
        include/Space/Normal_Space.h
        include/Space/Angular_Space.h
        include/Space/Start_Space.h
        include/Space/Space_Data.h
        src/Space/Space.cpp
        src/Space/Normal_Space.cpp
        src/Space/Angular_Space.cpp
        src/Space/Start_Space.cpp
)

target_link_libraries(Monopoly
        Space
)
