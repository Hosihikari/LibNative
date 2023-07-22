cmake_minimum_required(VERSION 3.26)
project(native CXX)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 26)

include_directories("include")

link_directories("lib")

target_link_libraries(hook "libfunchook.a")
target_link_libraries(hook "libZydis.a")

add_library(native SHARED src/hook.c src/native.cpp)

