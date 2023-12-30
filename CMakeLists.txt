cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(Monopoly)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
include_directories(src)

add_library(Space
        include/Space/Space_Data.h
        include/Space/Space.h
        include/Space/Normal_Space.h
        include/Space/Angular_Space.h
        include/Space/Start_Space.h
        src/Space/Space.cpp
        src/Space/Normal_Space.cpp
        src/Space/Angular_Space.cpp
        src/Space/Start_Space.cpp
)

add_library(Player
        include/Player/Player.h
        include/Player/Bank.h
        include/Player/Human_Player.h
        include/Player/Computer_Player.h
        src/Player/Player.cpp
        src/Player/Bank.cpp
        src/Player/Human_Player.cpp
        src/Player/Computer_Player.cpp
)

add_library(Game_Manager
        include/Game_manager/Game_Manager.h
        src/Game_manager/Game_Manager.cpp
)

add_library(Gameboard
        include/Gameboard/Gameboard.h
        src/Gameboard/Gameboard.cpp
)

target_link_libraries(Game_Manager
        Player
        Space
        Gameboard
)

add_executable(Monopoly
        include/Colors.h
        src/main.cpp)

target_link_libraries(Monopoly
        Game_Manager
)