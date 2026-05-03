#include <iostream>
#include <string>
#include "ZadSwitch.h"
#include "ZadParzysta.h"

using namespace std;

// W jezyku C/C++ instrukcja switch dziala tylko na typach calkowitych
// (lub typach wyliczeniowych) - nie mozna bezposrednio porownywac calych
// napisow std::string. Dwa typowe obejscia:
//   1. Lancuch if/else if (najprostsze).
//   2. Mapowanie napisu na wartosc int/enum (np. funkcja hashujaca albo
//      tabela [napis -> id]) i uzycie tego id w switchu.
// Ponizej demonstrujemy oba sposoby.

enum Wybor {
    BITOWO    = 1,
    MODULO    = 2,
    WARUNKOWO = 3,
    NIEZNANY  = 0,
};

static Wybor mapujNaWybor(const string& slowo) {
    if (slowo == "bitowo")    return BITOWO;
    if (slowo == "modulo")    return MODULO;
    if (slowo == "warunkowo") return WARUNKOWO;
    return NIEZNANY;
}

int ZadSwitch::main(int argc, char* argv[]) {
    string slowo = "modulo";
    int liczba = 9;

    if (argc >= 2) slowo  = argv[1];
    if (argc >= 3) liczba = stoi(argv[2]);

    cout << "Slowo = \"" << slowo << "\", liczba = " << liczba << endl;

    Wybor w = mapujNaWybor(slowo);

    bool wynik = false;
    switch (w) {
        case BITOWO:
            cout << "[switch] -> bitowo" << endl;
            wynik = czyParzystaBitowo(liczba);
            break;
        case MODULO:
            cout << "[switch] -> modulo" << endl;
            wynik = czyParzystaModulo(liczba);
            break;
        case WARUNKOWO:
            cout << "[switch] -> warunkowo" << endl;
            wynik = czyParzystaWarunkowo(liczba);
            break;
        case NIEZNANY:
        default:
            cout << "[switch] -> nieznane slowo (uzyj: bitowo / modulo / warunkowo)" << endl;
            return 1;
    }

    cout << liczba << (wynik ? " jest parzysta" : " jest nieparzysta") << endl;
    return 0;
}
