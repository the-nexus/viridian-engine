cmake_minimum_required (VERSION 3.8)
project (ViridianGraphics VERSION 0.0.1 LANGUAGES CXX)
message (STATUS ${PROJECT_NAME} ": Version " ${PROJECT_VERSION})

file (GLOB_RECURSE GFX_FILES ./*.h* ./*.c*)
source_group (TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${GFX_FILES})

add_library (${PROJECT_NAME} ${GFX_FILES})
target_compile_features (${PROJECT_NAME} PRIVATE cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES
    FOLDER "ViridianModules"
)

# Link dependencies
target_include_directories (${PROJECT_NAME}
    PUBLIC ../external/glfw/include
    PUBLIC ../external/glad/include
    PUBLIC ../external/glm/glm
)

target_link_directories (${PROJECT_NAME}
    PUBLIC ../external/glfw/src
    PUBLIC ../external/glad/src
    PUBLIC ../external/glm/glm
)

target_link_libraries (${PROJECT_NAME}
    glfw
    glad
    glm
)
