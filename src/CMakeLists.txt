
cmake_minimum_required (VERSION 3.8)

set (EXT_DIR ./external)

file (GLOB_RECURSE ENGINE_FILES
    ./core/*.h* ./core/*.c*
    ./rendering/*.h* ./rendering/*.c*
)

# Create and setup project and executable
project (CeruleanEngine CXX)
add_executable (${PROJECT_NAME} ${ENGINE_FILES})
target_compile_features (${PROJECT_NAME} PRIVATE cxx_std_17)

# Link libraries and external dependencies
add_subdirectory (${EXT_DIR}/glfw)
add_subdirectory (${EXT_DIR}/glm)

target_include_directories (${PROJECT_NAME}
    PUBLIC ${EXT_DIR}/glfw/include
    PUBLIC ${EXT_DIR}/glm/glm
)

target_link_directories (${PROJECT_NAME}
    PUBLIC ${EXT_DIR}/glfw/src
    PUBLIC ${EXT_DIR}/glm/glm
)

target_link_libraries (${PROJECT_NAME}
    glfw
    glm
)

# Create the groups for engine files
# https://stackoverflow.com/questions/31422680/how-to-set-visual-studio-filters-for-nested-sub-directory-using-cmake
source_group (TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ENGINE_FILES})
