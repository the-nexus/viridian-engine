#!/bin/sh

SOLUTION_DIR="bin/"
SOURCE_DIR="src/"

# Create the solution directory if it doesn't exist then move to it
if [ ! -d $SOLUTION_DIR ]; then
    mkdir $SOLUTION_DIR
fi

cd $SOLUTION_DIR

# Generate (or regenerate) the solution right here based on the CMakeList.txt in the source folder
cmake ../$SOURCE_DIR
