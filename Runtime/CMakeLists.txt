
#######################
## Configure library ##

project (ViridianRuntime CXX)
set (LIBRARY_ALIAS_NAME Viridian::Runtime)

#####################
## Create library ##

file (GLOB_RECURSE FILES_SOURCE *.c *.cpp)
file (GLOB_RECURSE FILES_INLINE *.inl)
file (GLOB_RECURSE FILES_HEADER *.h *.hpp)

source_group (TREE ${PROJECT_SOURCE_DIR} FILES ${FILES_SOURCE} ${FILES_INLINE} ${FILES_HEADER})

add_library (${PROJECT_NAME} SHARED ${FILES_SOURCE} ${FILES_INLINE} ${FILES_HEADER})
add_library (${LIBRARY_ALIAS_NAME} ALIAS ${PROJECT_NAME})

set_target_properties (${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories (${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})

#######################
## Link dependencies ##

target_link_libraries (${PROJECT_NAME}
    PUBLIC Viridian::Graphics
)
