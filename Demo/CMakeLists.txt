
##########################
## Configure executable ##

project (ViridianDemo CXX)

#######################
## Create executable ##

file (GLOB_RECURSE FILES_SOURCE *.c *.cpp)
file (GLOB_RECURSE FILES_INLINE *.inl)
file (GLOB_RECURSE FILES_HEADER *.h *.hpp)

source_group (TREE ${PROJECT_SOURCE_DIR} FILES ${FILES_SOURCE} ${FILES_INLINE} ${FILES_HEADER})

add_executable (${PROJECT_NAME} ${FILES_SOURCE} ${FILES_INLINE} ${FILES_HEADER})

target_include_directories (${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR})

#######################
## Link dependencies ##

target_link_libraries (${PROJECT_NAME}
    PRIVATE Viridian::Runtime
)
