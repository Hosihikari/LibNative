cmake_minimum_required(VERSION 3.26)
project(native CXX)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 26)

include_directories("include")

link_directories("lib")

add_library(native SHARED src/hook.cpp src/native.cpp)

target_link_libraries(native "libfunchook.a"
                             "libZydis.a")
