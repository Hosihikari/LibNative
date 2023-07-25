cmake_minimum_required(VERSION 3.26)

set(CMAKE_C_COMPILER clang)
set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_COMPILER clang)
set(CMAKE_CXX_STANDARD 26)

project(native C CXX)

include_directories("include")

link_directories("lib")

add_library(native SHARED src/hook.c src/native.cpp)

target_link_libraries(native "libfunchook.a"
                             "libZydis.a")
