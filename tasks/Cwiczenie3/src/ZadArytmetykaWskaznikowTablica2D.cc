#include <iostream>
#include "ZadArytmetykaWskaznikowTablica2D.h"

using namespace std;

// W C/C++ tablica dwuwymiarowa Tab[3][3] jest w pamieci ukladana
// w porzadku "row-major" - najpierw caly wiersz 0, potem caly wiersz 1, itd.
// Innymi slowy: &Tab[0][0], &Tab[0][1], &Tab[0][2], &Tab[1][0], &Tab[1][1] ...
// stanowia jedna ciagla strefe pamieci, w ktorej indeks kolumny zmienia sie
// najszybciej, a indeks wiersza najwolniej.

int ZadArytmetykaWskaznikowTablica2D::main() {
    int Tab[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Adresy elementow Tab[3][3] w kolejnosci [wiersz][kolumna]:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "  Tab[" << i << "][" << j << "] = " << Tab[i][j]
                 << "  adres = " << &Tab[i][j] << endl;
        }
    }

    cout << "\nIteracja przez tablice jako jeden ciagly blok pamieci:" << endl;
    int* p = &Tab[0][0];
    for (int k = 0; k < 9; ++k) {
        cout << "  *(p+" << k << ") = " << *(p + k)
             << "  adres = " << (p + k) << endl;
    }

    cout << "\nWniosek: rozklad row-major - najszybciej zmienia sie kolumna." << endl;

    return 0;
}
