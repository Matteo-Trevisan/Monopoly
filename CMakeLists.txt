cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(Monopoly)

set(CMAKE_CXX_STANDARD 11)

add_compile_options(-O2)

include_directories(include)
include_directories(src)

add_executable(Monopoly
        src/main.cpp)

add_library(Space
        include/Space/Space_Data.h
        include/Space/Space.h
        src/Space/Space.cpp
)

add_library(Derived_Space
        include/Space/Normal_Space.h
        include/Space/Angular_Space.h
        include/Space/Start_Space.h
        src/Space/Normal_Space.cpp
        src/Space/Angular_Space.cpp
        src/Space/Start_Space.cpp
        include/Game_manager/Reprint.h
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
        src/Game_manager/Reprint.cpp
)

add_library(Gameboard
        include/Gameboard/Gameboard.h
        src/Gameboard/Gameboard.cpp
        include/Colors.h
)

target_link_libraries(Space
        Derived_Space
        Player
)

target_link_libraries(Game_Manager
        Gameboard
        Space
)

target_link_libraries(Monopoly
        Game_Manager
)
