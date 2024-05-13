cmake_minimum_required(VERSION 3.12)
project(University CXX)

set(CMAKE_CXX_STANDARD 20)

# Add all the source files in the current directory
file(GLOB SOURCES "*.cpp")

add_executable(University ${SOURCES})