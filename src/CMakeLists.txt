
cmake_minimum_required (VERSION 3.8)

project (CeruleanEngine CXX)
file (GLOB_RECURSE SOURCE_LIST *.h* *.c*)

add_executable (CeruleanEngine ${SOURCE_LIST})
target_compile_features (CeruleanEngine PRIVATE cxx_std_17)

# Create the source groups for source tree with root at CMAKE_CURRENT_SOURCE_DIR
# https://stackoverflow.com/questions/31422680/how-to-set-visual-studio-filters-for-nested-sub-directory-using-cmake
source_group (TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_LIST})
