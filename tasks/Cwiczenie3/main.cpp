#include "ZadArytmetykaWskaznikowZamiana.h"
#include "ZadArytmetykaWskaznikowSuma.h"
#include "ZadArytmetykaWskaznikowZnajdowanie.h"
#include "ZadArytmetykaWskaznikowPrzesuniecie.h"
#include "ZadArytmetykaWskaznikowRoznica.h"
#include "ZadArytmetykaWskaznikowKopiowanie.h"
#include "ZadAdresowaniePamieci.h"
#include "ZadArytmetykaWskaznikowTabliceA.h"
#include "ZadArytmetykaWskaznikowTabliceB.h"
#include "ZadArytmetykaWskaznikowTablica2D.h"
#include "ZadArytmetykaWskaznikow.h"
#include "ZadOperatoryPrzypisania.h"
#include "ZadBitoweOperatoryLogiczneSingleVariable.h"

#include <string>
#include <iostream>
using namespace std;

int mapFunctions(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Dostepne parametry:" << endl;
        cout << "3.1  - Zamiana dwoch liczb przez wskazniki" << endl;
        cout << "3.2  - Sumowanie elementow tablicy" << endl;
        cout << "3.3  - Znajdowanie najwiekszego elementu" << endl;
        cout << "3.4  - Przesuniecie tablicy w prawo" << endl;
        cout << "3.5  - Roznica dwoch wskaznikow" << endl;
        cout << "3.6  - Kopiowanie tablicy" << endl;
        cout << "3.7  - Adresowanie pamieci - kierunek" << endl;
        cout << "3.8  - Operacje na tablicy (suma, max, odwrocenie)" << endl;
        cout << "3.9  - Operacje na dwoch tablicach" << endl;
        cout << "3.10 - Tablica dwuwymiarowa - adresowanie" << endl;
        cout << "3.11 - Operacje wskaznikowe + tabelka A,B,C" << endl;
        cout << "3.12 - Operatory arytmetyczne i przypisania" << endl;
        cout << "3.15 <8 bitow> - Tablica 8 bitow -> liczba" << endl;
        return 1;
    }

    string arg = argv[1];
    if (arg == "3.1") {
        return ZadArytmetykaWskaznikowZamiana().main();
    } else if (arg == "3.2") {
        return ZadArytmetykaWskaznikowSuma().main();
    } else if (arg == "3.3") {
        return ZadArytmetykaWskaznikowZnajdowanie().main();
    } else if (arg == "3.4") {
        return ZadArytmetykaWskaznikowPrzesuniecie().main();
    } else if (arg == "3.5") {
        return ZadArytmetykaWskaznikowRoznica().main();
    } else if (arg == "3.6") {
        return ZadArytmetykaWskaznikowKopiowanie().main();
    } else if (arg == "3.7") {
        return ZadAdresowaniePamieci().main();
    } else if (arg == "3.8") {
        return ZadArytmetykaWskaznikowTabliceA().main();
    } else if (arg == "3.9") {
        return ZadArytmetykaWskaznikowTabliceB().main();
    } else if (arg == "3.10") {
        return ZadArytmetykaWskaznikowTablica2D().main();
    } else if (arg == "3.11") {
        return ZadArytmetykaWskaznikow().main();
    } else if (arg == "3.12") {
        return ZadOperatoryPrzypisania().main();
    } else if (arg == "3.15") {
        for (int i = 1; i < argc - 1; ++i) argv[i] = argv[i + 1];
        argc -= 1;
        return ZadBitoweOperatoryLogiczneSingleVariable().main(argc, argv);
    } else {
        cout << "Nieznana opcja: " << arg << endl;
        return 1;
    }
}

int main(int argc, char* argv[]) {
    return mapFunctions(argc, argv);
}
