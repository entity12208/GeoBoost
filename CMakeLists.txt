cmake_minimum_required(VERSION 3.10)
project(GeoBoost)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)
include_directories(include/imgui)
include_directories(include/minhook)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add ImGui source files
set(IMGUI_SOURCES
    include/imgui/imgui.cpp
    include/imgui/imgui_draw.cpp
    include/imgui/imgui_tables.cpp
    include/imgui/imgui_widgets.cpp
    include/imgui/backends/imgui_impl_dx9.cpp
    include/imgui/backends/imgui_impl_win32.cpp
)

# Add MinHook source files
set(MINHOOK_SOURCES
    src/minhook/buffer.c
    src/minhook/hook.c
    src/minhook/trampoline.c
)

# Add library
add_library(GeoBoost SHARED ${SOURCES} ${IMGUI_SOURCES} ${MINHOOK_SOURCES})

# Link libraries
target_link_libraries(GeoBoost d3d9 d3dx9)
