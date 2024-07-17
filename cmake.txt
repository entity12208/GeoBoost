cmake_minimum_required(VERSION 3.10)
project(GeoBoost)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)
include_directories(include/imgui)
include_directories(include/minhook)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add library
add_library(GeoBoost SHARED ${SOURCES})

# Link libraries
find_library(MINHOOK_LIBRARY NAMES libMinHook.a PATHS libs)
target_link_libraries(GeoBoost ${MINHOOK_LIBRARY} d3d9 d3dx9)

# Add ImGui source files
add_subdirectory(include/imgui)
target_link_libraries(GeoBoost imgui)
