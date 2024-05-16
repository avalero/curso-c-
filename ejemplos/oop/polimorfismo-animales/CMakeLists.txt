cmake_minimum_required(VERSION 3.0)
project(animales)

# Add all the .cpp files in the current directory to the source files
file(GLOB SOURCES "*.cpp")

# Add an executable target
add_executable(animales ${SOURCES})