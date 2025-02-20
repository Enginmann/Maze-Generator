cmake_minimum_required(VERSION 3.28)
project(Maze-Generator LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main "src/main.cpp" "src/Renderer.h" "src/Renderer.cpp" "src/MazeGenerator.h" "src/MazeGenerator.cpp" "src/Simulation.h" "src/Simulation.cpp" "src/Cell.h")
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)
