cmake_minimum_required(VERSION 3.12)
project(graph)

set(CMAKE_CXX_STANDARD 20)

# Add all .cpp files in the current directory and its subdirectories
set(SOURCES main.cpp Node.cpp)

add_executable(graph ${SOURCES})