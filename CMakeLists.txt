cmake_minimum_required(VERSION 3.5.0)
project(goofycast VERSION 0.1.0 LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(goofycast main.cpp)

# Since our project is name goofycast, we need to use the target name goofycast instead of raytracer (the example project name)
target_include_directories(goofycast PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/src/raymath"
    "${PROJECT_SOURCE_DIR}/src/rayimage"
    "${PROJECT_SOURCE_DIR}/src/lodepng"
    "${PROJECT_SOURCE_DIR}/src/userinputs"
    "${PROJECT_SOURCE_DIR}/src/vec3"
    "${PROJECT_SOURCE_DIR}/src/raytrace"
    "${PROJECT_SOURCE_DIR}/src/object"
    "${PROJECT_SOURCE_DIR}/src/gcast"
)

add_subdirectory(./src/raymath)
add_subdirectory(./src/rayimage)
add_subdirectory(./src/lodepng)
add_subdirectory(./src/userinputs)
add_subdirectory(./src/vec3)
add_subdirectory(./src/raytrace)
add_subdirectory(./src/object)
add_subdirectory(./src/gcast)

target_link_libraries(goofycast PUBLIC raymath rayimage lodepng userinputs vec3 raytrace object hittable gcast_utils)
