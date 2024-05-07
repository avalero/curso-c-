cmake_minimum_required(VERSION 3.0)

project(BasicOOP)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
    main.cpp
    Punto2d.cpp
    Punto2d.h
    #Student.cpp
    #Student.h
    #Teacher.cpp
    #Teacher.h
)

add_executable(BasicOOP ${SOURCE_FILES})