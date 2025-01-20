cmake_minimum_required(VERSION 3.28)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)

# Set architecture to arm64
set(CMAKE_OSX_ARCHITECTURES "arm64")

# Specify the SFML directory based on the output of brew --prefix sfml
set(SFML_DIR "/opt/homebrew/opt/sfml/lib/cmake/SFML")

# Find SFML package
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Include directories for SFML
include_directories("/opt/homebrew/opt/sfml/include")

add_executable(SnakeGame main.cpp
        Board.h
        Board.cpp
        TextureManager.cpp
        TextureManager.h
        Tile.h
        Tile.cpp)

# Link SFML libraries
target_link_libraries(SnakeGame sfml-system sfml-window sfml-graphics)