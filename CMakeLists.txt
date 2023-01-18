cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(battaglia_navale CXX)

add_library(Griglia STATIC lib/Griglia/Griglia.cpp)
target_include_directories(Griglia PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Griglia)
set_target_properties(Griglia PROPERTIES LINKER_LANGUAGE CXX)

add_library(Corazzata STATIC lib/Naval_units/Corazzata.cpp)
target_include_directories(Corazzata PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Naval_units)
set_target_properties(Corazzata PROPERTIES LINKER_LANGUAGE CXX)
add_library(Sottomarino STATIC lib/Naval_units/Sottomarino.cpp)
target_include_directories(Sottomarino PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Naval_units)
set_target_properties(Sottomarino PROPERTIES LINKER_LANGUAGE CXX)
add_library(Supporto STATIC lib/Naval_units/Supporto.cpp)
target_include_directories(Supporto PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Naval_units)
set_target_properties(Supporto PROPERTIES LINKER_LANGUAGE CXX)

add_library(Naval_battle STATIC lib/Naval_battle/Naval_battle.cpp)
target_include_directories(Naval_battle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Naval_battle)
set_target_properties(Naval_battle PROPERTIES LINKER_LANGUAGE CXX)

add_library(Replay STATIC lib/Replay/Replay.cpp)
target_include_directories(Replay PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Replay)
set_target_properties(Replay PROPERTIES LINKER_LANGUAGE CXX)

add_executable(battaglia_navale src/battaglia_navale.cpp)
add_executable(replay src/replay.cpp)

target_link_libraries(battaglia_navale PUBLIC Naval_battle)
target_link_libraries(replay PUBLIC Replay)
target_link_libraries(Replay PUBLIC Griglia Corazzata Supporto Sottomarino)
target_link_libraries(Naval_battle PUBLIC Griglia Corazzata Supporto Sottomarino)
target_link_libraries(Corazzata PUBLIC Griglia)
target_link_libraries(Sottomarino PUBLIC Griglia)
target_link_libraries(Supporto PUBLIC Griglia)



