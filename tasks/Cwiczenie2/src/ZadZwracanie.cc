#include <iostream>
#include <string>
#include "ZadZwracanie.h"

using namespace std;

int zwrocPrzezWartosc(int liczba) {
    return liczba;
}

int& zwrocPrzezReferencje(int& liczba) {
    return liczba;
}

int* zwrocPrzezWskaznik(int* liczba) {
    return liczba;
}

int* zwrocTablice() {
    static int tablica[5] = {10, 20, 30, 40, 50};
    return tablica;
}

int ZadZwracanie::main() {
    int a = 7;
    int b = 15;

    int wartosc = zwrocPrzezWartosc(a);
    cout << "1) Zwrot przez wartosc: " << wartosc << endl;

    int& ref = zwrocPrzezReferencje(a);
    ref = 99;
    cout << "2) Zwrot przez referencje: a = " << a << endl;

    int* wsk = zwrocPrzezWskaznik(&b);
    *wsk = 123;
    cout << "3) Zwrot przez wskaznik: b = " << b << endl;

    int* tab = zwrocTablice();
    cout << "4) Zwrot tablicy (wskaznik do pierwszego elementu): ";
    for (int i = 0; i < 5; ++i) {
        cout << tab[i] << " ";
    }
    cout << endl;

    return 0;
}
