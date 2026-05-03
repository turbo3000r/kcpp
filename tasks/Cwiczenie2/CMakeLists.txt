cmake_minimum_required(VERSION 3.14)
project(Cwiczenie2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Cwiczenie2
    main.cpp
    src/ZadZwracanie.cc
    src/ZadPrzeciazaniePole.cc
    src/ZadPrzeciazanieDodaj.cc
    src/ZadPrzeciazaniePlus.cc
    src/ZadPrzeciazaniePotega.cc
    src/ZadPrzekazywanieTablic.cc
    src/ZadPrzekazywanieTablicKopia.cc
)
target_include_directories(Cwiczenie2 PRIVATE include)
