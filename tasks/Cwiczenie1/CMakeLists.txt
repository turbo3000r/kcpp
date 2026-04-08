cmake_minimum_required(VERSION 3.14)
project(Cwiczenie1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Cwiczenie1
    main.cpp
    src/ZadEnumExample.cc
    src/ZadMainExample.cc
    src/ZadClassExample.cc
    src/ZadStringExample.cc
)
target_include_directories(Cwiczenie1 PRIVATE include)
