cmake_minimum_required(VERSION 3.14)
project(Task2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Task2 main.cpp src/Shape.cpp)
target_include_directories(Task2 PRIVATE include)
