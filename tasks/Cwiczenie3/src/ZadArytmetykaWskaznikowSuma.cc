#include <iostream>
#include "ZadArytmetykaWskaznikowSuma.h"

using namespace std;

int suma(const int* tab, size_t rozmiar) {
    int wynik = 0;
    for (size_t i = 0; i < rozmiar; ++i) {
        wynik += *(tab + i);
    }
    return wynik;
}

int ZadArytmetykaWskaznikowSuma::main() {
    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t n = sizeof(tab) / sizeof(tab[0]);

    cout << "Tablica: ";
    for (size_t i = 0; i < n; ++i) cout << tab[i] << " ";
    cout << endl;

    cout << "Suma elementow = " << suma(tab, n) << endl;
    return 0;
}
