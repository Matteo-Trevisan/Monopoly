cmake_minimum_required(VERSION 3.00 FATAL_ERROR)
project(Monopoly)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
include_directories(src)

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

add_library(Player
        include/Player/Player.h
        src/Player/Player.cpp
        src/Player/Human_Player.cpp
        include/Player/Human_Player.h
        src/Player/Computer_Player.cpp
        include/Player/Computer_Player.h
)

add_library(Game_Manager
        include/Game_manager/Game_Manager.h
        src/Game_manager/Game_Manager.cpp
)

add_library(Gameboard
        include/Gameboard/Gameboard.h
        src/Gameboard/Gameboard.cpp
)

add_executable(Monopoly
        src/main.cpp)

target_link_libraries(Monopoly
        Space
        Player
        Game_Manager
        Gameboard
)
