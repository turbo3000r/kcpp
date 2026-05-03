#include <iostream>
#include "ZadArytmetykaWskaznikowTabliceA.h"

using namespace std;

int ZadArytmetykaWskaznikowTabliceA::main() {
    static int tab[10];
    const int N = 10;

    for (int* p = tab; p < tab + N; ++p) {
        *p = static_cast<int>(p - tab) + 1;
    }

    cout << "Tablica wypelniona wartosciami 1..10:" << endl;
    for (const int* p = tab; p < tab + N; ++p) cout << *p << " ";
    cout << endl;

    int suma = 0;
    for (const int* p = tab; p < tab + N; ++p) suma += *p;
    cout << "Suma elementow = " << suma << endl;

    const int* maks = tab;
    for (const int* p = tab + 1; p < tab + N; ++p) {
        if (*p > *maks) maks = p;
    }
    cout << "Maksymalny element = " << *maks
         << " (adres " << maks << ", indeks " << (maks - tab) << ")" << endl;

    int* lewy = tab;
    int* prawy = tab + N - 1;
    while (lewy < prawy) {
        int tmp = *lewy;
        *lewy = *prawy;
        *prawy = tmp;
        ++lewy;
        --prawy;
    }

    cout << "Tablica po odwroceniu (bez []): ";
    for (const int* p = tab; p < tab + N; ++p) cout << *p << " ";
    cout << endl;

    return 0;
}
