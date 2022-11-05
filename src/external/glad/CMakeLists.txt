cmake_minimum_required (VERSION 3.8)
project (glad VERSION 1.0 LANGUAGES C)
message (STATUS "GLAD: Vulkan and OpenGL 4.6")

file (GLOB_RECURSE SRC_FILES ./src/*.h* ./src/*.c*)
source_group (TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC_FILES})

add_library(${PROJECT_NAME} ${SRC_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES
    FOLDER "GLAD"
)

target_include_directories (glad PRIVATE ./include/)
