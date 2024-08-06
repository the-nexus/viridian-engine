
#############
## GLOBALS ##

cmake_minimum_required (VERSION 3.22.1)

option (BUILD_DEMO "Build demo program" ON)

set (CMAKE_CXX_STANDARD 20)

#############
## PROJECT ##

project (ViridianEngine
    VERSION 0.1.0
    DESCRIPTION "C++ Rendering engine made to be used as a base for other projects"
    HOMEPAGE_URL "https://github.com/the-nexus/viridian-engine"
    LANGUAGES CXX
)

add_subdirectory (./Graphics)
add_subdirectory (./Runtime)

if (BUILD_DEMO)
    add_subdirectory (./Demo/)
endif (BUILD_DEMO)
 