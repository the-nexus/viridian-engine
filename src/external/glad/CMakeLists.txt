cmake_minimum_required (VERSION 3.8)
message (STATUS "GLAD: Vulkan and OpenGL 4.6")

file (GLOB_RECURSE SRC_FILES ./src/*.h* ./src/*.c*)
source_group (TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC_FILES})

project (glad VERSION 1.0 LANGUAGES C)
add_library(glad ${SRC_FILES})

target_include_directories (glad PRIVATE ./include/)

set_target_properties(glad PROPERTIES
    FOLDER "GLAD"
)
