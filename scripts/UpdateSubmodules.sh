#!/bin/sh

# Pull all the missing git submodule repositories (external libs)
git submodule update --init --recursive
