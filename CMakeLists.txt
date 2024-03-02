cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_COMPILER clang++)

project(export)

add_library(export SHARED src/export.cpp)
