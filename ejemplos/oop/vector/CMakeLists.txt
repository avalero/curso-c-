cmake_minimum_required(VERSION 3.0)

project(Vector)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
    main.cpp
    Vector.h
    Vector.cpp
    Vector2.h
    Vector2.cpp
)

add_executable(Vector ${SOURCE_FILES})