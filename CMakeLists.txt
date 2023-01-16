cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(battaglia_navale VERSION 1.0)

add_library(Griglia STATIC lib/Griglia/Griglia.hpp)
target_include_directories(Griglia PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Griglia)

add_library(Naval_battle STATIC lib/Naval_battle/Naval_battle.hpp)
target_include_directories(Naval_battle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Naval_battle)

target_include_directories(Naval_units PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Naval_units)
add_library(Corazzata STATIC lib/Naval_units/Corazzata.hpp)
target_include_directories(Corazzata PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Naval_units)
add_library(Sottomarino STATIC lib/Naval_units/Sottomarino.hpp)
target_include_directories(Sottomarino PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Naval_units)
add_library(Supporto STATIC lib/Naval_units/Supporto.hpp)
target_include_directories(Supporto PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Naval_units)

add_library(Replay STATIC lib/Replay/Replay.hpp)
target_include_directories(Replay PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Replay)


add_executable(battaglia_navale src/battaglia_navale.cpp)
add_executable(replay src/replay.cpp)

target_link_libraries(battaglia_navale PUBLIC Naval_battle)
target_link_libraries(replay PUBLIC Replay)