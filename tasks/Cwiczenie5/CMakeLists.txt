cmake_minimum_required(VERSION 3.14)
project(Cwiczenie5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Cwiczenie5
    main.cpp
    src/ZadClass.cc
    src/ZadStruct.cc
    src/ZadUnia.cc
    src/ZadKlasaKonstruktor.cc
    src/ZadStructKonstruktor.cc
    src/ZadPrzyjazn.cc
    src/ZadMetodyAbstrakcyjne.cc
)
target_include_directories(Cwiczenie5 PRIVATE include)
