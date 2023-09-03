cmake_minimum_required(VERSION 3.15.0)
project(sfml-app VERSION 0.1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set (SOURCES
    app/main.cpp
    app/entity/src/entity.cpp
    app/entity/src/player_graphics_component.cpp
    app/entity/src/player_input_component.cpp
    app/entity/src/player_physics_component.cpp
    app/state/src/game.cpp
    app/state/src/game_state.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCES})
include_directories(app/entity/include)
include_directories(app/state/include)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

# target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
