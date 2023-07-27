cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 26)

project(native CXX)

include_directories("include")

link_directories("lib")

add_library(native SHARED src/native.cpp)
