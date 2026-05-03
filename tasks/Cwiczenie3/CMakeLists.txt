cmake_minimum_required(VERSION 3.14)
project(Cwiczenie3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Cwiczenie3
    main.cpp
    src/ZadArytmetykaWskaznikowZamiana.cc
    src/ZadArytmetykaWskaznikowSuma.cc
    src/ZadArytmetykaWskaznikowZnajdowanie.cc
    src/ZadArytmetykaWskaznikowPrzesuniecie.cc
    src/ZadArytmetykaWskaznikowRoznica.cc
    src/ZadArytmetykaWskaznikowKopiowanie.cc
    src/ZadAdresowaniePamieci.cc
    src/ZadArytmetykaWskaznikowTabliceA.cc
    src/ZadArytmetykaWskaznikowTabliceB.cc
    src/ZadArytmetykaWskaznikowTablica2D.cc
    src/ZadArytmetykaWskaznikow.cc
    src/ZadOperatoryPrzypisania.cc
    src/ZadBitoweOperatoryLogiczneSingleVariable.cc
)
target_include_directories(Cwiczenie3 PRIVATE include)
