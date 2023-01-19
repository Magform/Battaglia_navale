cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(battaglia_navale CXX)

include_directories(include)

add_library(naval_battle_and_replay
	lib/Corazzata.cpp
	lib/Griglia.cpp
	lib/Naval_battle.cpp
	lib/replay.cpp
	lib/Sottomarino.cpp
	lib/Supporto.cpp)

add_executable(battaglia_navale src/battaglia_navale.cpp)
add_executable(replay src/replay.cpp)

target_link_libraries(battaglia_navale naval_battle_and_replay)
target_link_libraries(replay naval_battle_and_replay)
