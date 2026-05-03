#include <iostream>
#include <bitset>
#include <string>
#include "ZadBitoweOperatoryLogiczneSingleVariable.h"

using namespace std;

// Program przyjmuje 8-elementowa tablice bitow (kazdy 0 lub 1) i
// zwraca jedna liczbe calkowita, ktora w zapisie binarnym ma 1 na
// pozycjach odpowiadajacych jedynkom w tablicy.
//
// Przyklad: tab = {1,0,1,1,0,0,0,1}  ->  bin: 10110001 = 0xB1 = 177
//
// Konwencja: tab[0] traktujemy jako BIT NAJBARDZIEJ ZNACZACY (MSB),
// tab[7] jako bit najmniej znaczacy (LSB).

int ZadBitoweOperatoryLogiczneSingleVariable::main(int argc, char* argv[]) {
    int tab[8];

    if (argc >= 9) {
        for (int i = 0; i < 8; ++i) {
            int v = stoi(argv[i + 1]);
            tab[i] = (v != 0) ? 1 : 0;
        }
    } else {
        int wzor[8] = {1, 0, 1, 1, 0, 0, 0, 1};
        for (int i = 0; i < 8; ++i) tab[i] = wzor[i];
        cout << "Brak 8 argumentow - uzywam wzorca: ";
        for (int i = 0; i < 8; ++i) cout << tab[i];
        cout << endl;
    }

    unsigned int wynik = 0;
    for (int i = 0; i < 8; ++i) {
        if (tab[i]) {
            wynik |= (1u << (7 - i));
        }
    }

    cout << "Tablica wejsciowa: ";
    for (int i = 0; i < 8; ++i) cout << tab[i] << (i < 7 ? " " : "");
    cout << endl;

    cout << "Wynik (dec): " << wynik << endl;
    cout << "Wynik (hex): 0x" << hex << wynik << dec << endl;
    cout << "Wynik (bin): " << bitset<8>(wynik) << endl;

    return 0;
}
