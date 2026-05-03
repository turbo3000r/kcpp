cmake_minimum_required(VERSION 3.14)
project(Cwiczenie4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Cwiczenie4
    main.cpp
    src/ZadStringStream.cc
    src/ZadManipulacjaStrumieniemCout.cc
    src/ZadCinCoutFile.cc
    src/ZadCandCPP.cc
    src/ZadTabelaFormat.cc
    src/ZadTemperaturaFormat.cc
    src/ZadDaneNaukoweFormat.cc
    src/ZadParzysta.cc
    src/ZadParzystaCase.cc
    src/ZadPetle.cc
    src/ZadSwitch.cc
    src/ZadForA.cc
    src/ZadSilnia.cc
    src/ZadKsztalt.cc
    src/ZadWhileA.cc
    src/ZadGra.cc
    src/ZadStudent.cc
    src/ZadPreprocesor.cc
)
target_include_directories(Cwiczenie4 PRIVATE include)
