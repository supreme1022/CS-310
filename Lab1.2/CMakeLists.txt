cmake_minimum_required(VERSION 3.20)
project(SerializationLab CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# nlohmann/json (JSON)
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(json)

# yaml-cpp (YAML)
FetchContent_Declare(
  yaml-cpp
  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
  GIT_TAG yaml-cpp-0.7.0
)
FetchContent_MakeAvailable(yaml-cpp)

# Catch2 (tests)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.6.0
)
FetchContent_MakeAvailable(catch2)

add_library(core
  src/person.cpp
  src/student.cpp
  src/instructor.cpp
)
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(core PUBLIC nlohmann_json::nlohmann_json yaml-cpp)

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE core)

# ----------------------------
# Testing setup
# ----------------------------
include(CTest)
enable_testing()

# Build the test executable (renamed to test_serialization for clarity)
add_executable(test_serialization tests/test_serialization.cpp)
target_link_libraries(test_serialization PRIVATE core Catch2::Catch2WithMain)

# Catch2 test discovery
include(${catch2_SOURCE_DIR}/extras/Catch.cmake)
catch_discover_tests(test_serialization)

# Manual fallback in case discovery fails
add_test(NAME serialization_tests COMMAND test_serialization)