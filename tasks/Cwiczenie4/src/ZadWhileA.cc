#include <iostream>
#include "ZadWhileA.h"

using namespace std;

int ZadWhileA::main() {
    cout << "Podawaj liczby. Wpisz 0 lub znak nieliczbowy aby zakonczyc." << endl;

    int liczba = 0;
    long long suma = 0;
    int liczbaWartosci = 0;
    int liczbaNiedodatnich = 0;

    while (cin >> liczba && liczba != 0) {
        ++liczbaWartosci;
        if (liczba <= 0) {
            ++liczbaNiedodatnich;
            cout << "  uwaga: " << liczba << " nie jest liczba dodatnia." << endl;
        }
        suma += liczba;
    }

    cout << "\nLiczba wprowadzonych wartosci: " << liczbaWartosci << endl;
    cout << "Suma:                          " << suma << endl;
    cout << "W tym niedodatnich:            " << liczbaNiedodatnich << endl;

    return 0;
}
