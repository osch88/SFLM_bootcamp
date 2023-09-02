cmake_minimum_required(VERSION 3.15.0)
project(sfml-app VERSION 0.1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set (SOURCES
    src/main.cpp
    src/game.cpp
    src/game_state.cpp
    src/player.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCES})
include_directories(include)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

# target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
