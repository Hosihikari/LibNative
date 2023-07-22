cmake_minimum_required(VERSION 3.26)
project(hook C)
project(native CXX)

set(CMAKE_C_STANDARD 23)

include_directories("include")

link_directories(
        "lib"
)

add_library(hook SHARED src/hook.c)

target_link_libraries(hook "libfunchook.a")
target_link_libraries(hook "libZydis.a")

add_library(native SHARED src/native.cpp)

