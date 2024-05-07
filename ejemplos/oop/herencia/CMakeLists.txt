cmake_minimum_required(VERSION 3.0)

project(Herencia)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp polygon.cpp polygon.h regularpolygon.h regularpolygon.cpp Cuadrado.h Cuadrado.cpp)

add_executable(Herencia ${SOURCE_FILES})