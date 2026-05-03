#include <iostream>
#include "ZadArytmetykaWskaznikowZnajdowanie.h"

using namespace std;

int* maxElement(int* tab, size_t rozmiar) {
    if (rozmiar == 0) return nullptr;
    int* maks = tab;
    for (size_t i = 1; i < rozmiar; ++i) {
        if (*(tab + i) > *maks) {
            maks = tab + i;
        }
    }
    return maks;
}

int ZadArytmetykaWskaznikowZnajdowanie::main() {
    int tab[] = {3, 7, 2, 9, 4, 12, 5, 8};
    size_t n = sizeof(tab) / sizeof(tab[0]);

    cout << "Tablica: ";
    for (size_t i = 0; i < n; ++i) cout << tab[i] << " ";
    cout << endl;

    int* maks = maxElement(tab, n);
    cout << "Najwiekszy element = " << *maks
         << " (indeks " << (maks - tab) << ", adres " << maks << ")" << endl;
    return 0;
}
