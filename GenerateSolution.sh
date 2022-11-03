#!/bin/sh

BUILD_DIR="./bin/"
CMAKE_LIST_DIR="./src/"

# Update the Submodules to make sure they're downloaded before building
sh "./scripts/UpdateSubmodules.sh"

# Generate (or regenerate) the build solution based on the root CMakeList.txt
cmake -S $CMAKE_LIST_DIR -B $BUILD_DIR -DGLFW_BUILD_DOCS=OFF
