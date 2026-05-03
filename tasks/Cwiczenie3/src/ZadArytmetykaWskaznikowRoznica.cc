#include <iostream>
#include <cstddef>
#include "ZadArytmetykaWskaznikowRoznica.h"

using namespace std;

int ZadArytmetykaWskaznikowRoznica::main() {
    int tab[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int* p1 = &tab[2];
    int* p2 = &tab[7];

    cout << "Adres p1 (tab[2]) = " << p1 << ", wartosc = " << *p1 << endl;
    cout << "Adres p2 (tab[7]) = " << p2 << ", wartosc = " << *p2 << endl;

    // Roznica wskaznikow zwraca liczbe elementow miedzy nimi (typ ptrdiff_t),
    // a NIE roznice w bajtach.
    ptrdiff_t roznicaElementow = p2 - p1;
    long long roznicaBajtow =
        reinterpret_cast<char*>(p2) - reinterpret_cast<char*>(p1);

    cout << "Roznica wskaznikow (p2 - p1) = " << roznicaElementow
         << " elementow" << endl;
    cout << "W bajtach (sizeof(int) = " << sizeof(int) << "): "
         << roznicaBajtow << " bajtow" << endl;

    return 0;
}
