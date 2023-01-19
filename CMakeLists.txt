cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(battaglia_navale CXX)

include_directories(include)

add_library(naval_battle_lib
	lib/Griglia/Griglia.cpp
	lib/Naval_battle/Naval_battle.cpp
	lib/Naval_units/Corazzata.cpp
	lib/Naval_units/Sottomarino.cpp
	lib/Naval_units/Supporto.cpp)

add_library(replay_lib
	lib/Griglia/Griglia.cpp
	lib/Replay/Replay.cpp
	lib/Naval_units/Corazzata.cpp
	lib/Naval_units/Sottomarino.cpp
	lib/Naval_units/Supporto.cpp)

add_executable(battaglia_navale src/battaglia_navale.cpp)
add_executable(replay src/replay.cpp)

target_link_libraries(battaglia_navale naval_battle_lib)
target_link_libraries(replay replay_lib)
