cmake_minimum_required(VERSION 3.14)
project(Task1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Task1 main.cpp src/MathUtils.cpp)
target_include_directories(Task1 PRIVATE include)
