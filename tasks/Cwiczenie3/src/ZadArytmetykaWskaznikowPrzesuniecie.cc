#include <iostream>
#include "ZadArytmetykaWskaznikowPrzesuniecie.h"

using namespace std;

void przesun(int* tab, size_t rozmiar) {
    if (rozmiar < 2) return;
    int ostatni = *(tab + rozmiar - 1);
    for (int* p = tab + rozmiar - 1; p > tab; --p) {
        *p = *(p - 1);
    }
    *tab = ostatni;
}

static void wypisz(const int* tab, size_t n) {
    for (size_t i = 0; i < n; ++i) cout << *(tab + i) << " ";
    cout << endl;
}

int ZadArytmetykaWskaznikowPrzesuniecie::main() {
    int tab[] = {1, 2, 3, 4, 5, 6};
    size_t n = sizeof(tab) / sizeof(tab[0]);

    cout << "Przed przesunieciem: ";
    wypisz(tab, n);
    przesun(tab, n);
    cout << "Po przesunieciu:     ";
    wypisz(tab, n);

    return 0;
}
