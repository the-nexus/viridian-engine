cmake_minimum_required (VERSION 3.8)

set (EXT_DIR ./external)

file (GLOB_RECURSE ENGINE_FILES Main.cpp
    ./core/*.h* ./core/*.c*
)
source_group (TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ENGINE_FILES})

# Create and setup project and executable
project (CeruleanEngine CXX)
add_executable (${PROJECT_NAME} ${ENGINE_FILES})
target_compile_features (${PROJECT_NAME} PRIVATE cxx_std_17)

# Link children CMakeLists.txt files
add_subdirectory (./external/glfw)
add_subdirectory (./external/glad)
add_subdirectory (./external/glm)
add_subdirectory (./graphics)

# Link dependencies
target_include_directories (${PROJECT_NAME}
    PUBLIC ./graphics
)

target_link_directories (${PROJECT_NAME}
    PUBLIC ./graphics
)

target_link_libraries (${PROJECT_NAME}
    CeruleanGraphics
)
