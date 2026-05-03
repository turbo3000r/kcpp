#include <iostream>
#include <array>
#include "ZadPrzekazywanieTablicKopia.h"

using namespace std;

static void wypisz(const string& etykieta, const array<int, 5>& tab) {
    cout << etykieta;
    for (int v : tab) cout << v << " ";
    cout << endl;
}

void zmienKopie(array<int, 5> kopia) {
    for (auto& v : kopia) v *= 10;
    wypisz("  W funkcji (kopia po modyfikacji): ", kopia);
}

void zmienOryginal(array<int, 5>& referencja) {
    for (auto& v : referencja) v *= 10;
}

int ZadPrzekazywanieTablicKopia::main() {
    array<int, 5> oryginal = {1, 2, 3, 4, 5};

    cout << "Przekazywanie przez wartosc (kopia):" << endl;
    wypisz("  Przed wywolaniem:                ", oryginal);
    zmienKopie(oryginal);
    wypisz("  Po wywolaniu (oryginal):         ", oryginal);

    cout << "\nPrzekazywanie przez referencje (bez kopii):" << endl;
    wypisz("  Przed wywolaniem:                ", oryginal);
    zmienOryginal(oryginal);
    wypisz("  Po wywolaniu (oryginal):         ", oryginal);

    return 0;
}
