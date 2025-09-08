cmake_minimum_required(VERSION 3.10)
project(ShapeMaker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include headers
include_directories(include)

# Add source files
add_executable(shapemaker
    src/shapemaker.cpp
    src/main.cpp
)

# Unit tests
enable_testing()
add_executable(test_shapemaker tests/test_shapemaker.cpp src/shapemaker.cpp)
add_test(NAME ShapeMakerTests COMMAND test_shapemaker)