cmake_minimum_required(VERSION 3.5.0)
project(goofycast VERSION 0.1.0 LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(goofycast main.cpp)

# Since our project is name goofycast, we need to use the target name goofycast instead of raytracer (the example project name)
target_include_directories(goofycast PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/src/raymath"
                           )

add_subdirectory(./src/raymath)

target_link_libraries(goofycast PUBLIC raymath)