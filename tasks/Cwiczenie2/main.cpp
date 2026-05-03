#include "ZadZwracanie.h"
#include "ZadPrzeciazaniePole.h"
#include "ZadPrzeciazanieDodaj.h"
#include "ZadPrzeciazaniePlus.h"
#include "ZadPrzeciazaniePotega.h"
#include "ZadPrzekazywanieTablic.h"
#include "ZadPrzekazywanieTablicKopia.h"

#include <string>
#include <iostream>
using namespace std;

int mapFunctions(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Dostepne parametry:" << endl;
        cout << "2.1 - Zadanie 2.1 (zwracanie wartosci/referencji/wskaznika/tablicy)" << endl;
        cout << "2.2 - Zadanie 2.2 (przeciazanie funkcji pole)" << endl;
        cout << "2.3 - Zadanie 2.3 (przeciazanie funkcji dodaj)" << endl;
        cout << "2.4 - Zadanie 2.4 (przeciazenie operatora + dla klasy Punkt)" << endl;
        cout << "2.5 - Zadanie 2.5 (przeciazanie funkcji potega)" << endl;
        cout << "2.6 - Zadanie 2.6 (przekazywanie tablic z zachowaniem rozmiaru)" << endl;
        cout << "2.7 - Zadanie 2.7 (przekazywanie tablicy jako kopii)" << endl;
        return 1;
    }

    string arg = argv[1];
    if (arg == "2.1") {
        return ZadZwracanie().main();
    } else if (arg == "2.2") {
        return ZadPrzeciazaniePole().main();
    } else if (arg == "2.3") {
        return ZadPrzeciazanieDodaj().main();
    } else if (arg == "2.4") {
        return ZadPrzeciazaniePlus().main();
    } else if (arg == "2.5") {
        return ZadPrzeciazaniePotega().main();
    } else if (arg == "2.6") {
        return ZadPrzekazywanieTablic().main();
    } else if (arg == "2.7") {
        return ZadPrzekazywanieTablicKopia().main();
    } else {
        cout << "Nieznana opcja: " << arg << endl;
        return 1;
    }
}

int main(int argc, char* argv[]) {
    return mapFunctions(argc, argv);
}
