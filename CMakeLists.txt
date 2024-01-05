cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(Monopoly)

set(CMAKE_CXX_STANDARD 11)

add_compile_options(-O2)

include_directories(include)
include_directories(src)

add_executable(Monopoly src/main.cpp)


add_library(Space src/Space/Space.cpp)
add_library(Derived_Space
        include/Space/Normal_Space.h
        include/Space/Angular_Space.h
        include/Space/Start_Space.h
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
add_library(Gameboard
        include/Gameboard/Gameboard.h
        src/Gameboard/Gameboard.cpp
        include/Colors.h
)
add_library(Game_Manager
        include/Game_manager/Game_Manager.h
        src/Game_manager/Game_Manager.cpp

)


# Aggiungi le directory degli header per le librerie
target_include_directories(Space PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Space)
target_include_directories(Derived_Space PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Space)
target_include_directories(Player PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Player)
target_include_directories(Gameboard PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Gameboard)
target_include_directories(Game_Manager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Game_manager)

# Collega le librerie
target_link_libraries(Space Derived_Space Player)
target_link_libraries(Game_Manager Gameboard Space)
target_link_libraries(Monopoly Game_Manager)


