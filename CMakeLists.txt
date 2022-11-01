
cmake_minimum_required (VERSION 3.8)

set (EXT_DIR ./external)
set (SRC_DIR ./src)

file (GLOB_RECURSE SRC_FILES ${SRC_DIR}/*.h* ${SRC_DIR}/*.c*)

# Create and setup project and executable
project (CeruleanEngine CXX)
add_executable (${PROJECT_NAME} ${SRC_FILES})
target_compile_features (${PROJECT_NAME} PRIVATE cxx_std_17)

# Link libraries and external dependencies
add_subdirectory (${EXT_DIR}/glfw)

target_include_directories (${PROJECT_NAME}
    PUBLIC ${EXT_DIR}/glfw/include
)

target_link_directories (${PROJECT_NAME}
    PUBLIC ${EXT_DIR}/glfw/src
)

target_link_libraries(${PROJECT_NAME}
    glfw
)

# Create the source groups for source tree with root at CMAKE_CURRENT_SOURCE_DIR
# https://stackoverflow.com/questions/31422680/how-to-set-visual-studio-filters-for-nested-sub-directory-using-cmake
source_group (TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC_FILES})
