cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME Battaglia_Navale)
project(${PROJECT_NAME} VERSION 1.0)

set(SRC_FILES lib/Griglia/Griglia.hpp lib/Naval_battle/Naval_battle.hpp lib/Naval_units/Corazzata.hpp lib/Naval_units/Sottomarino.hpp lib/Naval_units/Supporto.hpp lib/Replay/Replay.hpp)
set(HEADER_FILE include/Griglia/Griglia.h include/Naval_battle/Naval_battle.h include/Naval_units/Corazzata.h include/Naval_units/Naval_units.h include/Naval_units/Sottomarino.h lib/Naval_units/Supporto.hpp lib/Replay/Replay.hpp)

include_directory(include lib)

add_library(
    Naval_battle
    ${SRC_FILES}
    ${HEADER_FILE}
)

add_executable(battaglia_navale src/battaglia_navale.cpp)
add_executable(replay src/replay.cpp)

target_link_libraries(battaglia_navale Naval_battle)
target_link_libraries(replay Naval_battle)
