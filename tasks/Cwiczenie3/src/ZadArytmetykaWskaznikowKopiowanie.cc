#include <iostream>
#include "ZadArytmetykaWskaznikowKopiowanie.h"

using namespace std;

void kopiujTablice(const int* zrodlo, int* cel, size_t rozmiar) {
    const int* zEnd = zrodlo + rozmiar;
    while (zrodlo != zEnd) {
        *cel = *zrodlo;
        ++cel;
        ++zrodlo;
    }
}

int ZadArytmetykaWskaznikowKopiowanie::main() {
    int zrodlo[] = {11, 22, 33, 44, 55, 66, 77};
    size_t n = sizeof(zrodlo) / sizeof(zrodlo[0]);
    int cel[7] = {0};

    kopiujTablice(zrodlo, cel, n);

    cout << "Zrodlowa: ";
    for (size_t i = 0; i < n; ++i) cout << *(zrodlo + i) << " ";
    cout << endl;

    cout << "Docelowa: ";
    for (size_t i = 0; i < n; ++i) cout << *(cel + i) << " ";
    cout << endl;

    return 0;
}
