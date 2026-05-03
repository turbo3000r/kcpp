#include <iostream>
#include "ZadAdresowaniePamieci.h"

using namespace std;

// -----------------------------------------------------------------------------
// Kierunek adresowania pamieci - komentarz wyjasniajacy:
//
// Zmienne lokalne ("automatyczne") sa odkladane na stosie, ktory na wiekszosci
// architektur (x86, x86_64, ARM) "rosnie w dol", tzn. kazda kolejna
// zaalokowana zmienna otrzymuje adres MNIEJSZY niz poprzednia.
// W konsekwencji jesli zadeklarujemy pod soba kilka zmiennych:
//     int a; int b; int c;
// to typowo &a > &b > &c (chociaz standard tego nie gwarantuje, kompilator
// moze zmienne przemieszczac, dopelniac (padding) lub trzymac w rejestrach
// przy optymalizacji).
//
// Z kolei elementy tablicy leza ZAWSZE w pamieci jeden za drugim,
// w kolejnosci rosnacej: &tab[0] < &tab[1] < &tab[2] ...
// (roznica adresow miedzy sasiednimi elementami = sizeof(typ)).
//
// Zmienne globalne i statyczne lezaa w segmentach .data / .bss i typowo
// rosna w gore, niezaleznie od kierunku stosu.
// -----------------------------------------------------------------------------

static int globalna1 = 1;
static int globalna2 = 2;

int ZadAdresowaniePamieci::main() {
    int a = 10;
    int b = 20;
    int c = 30;
    int tab[5] = {0, 0, 0, 0, 0};

    cout << "Zmienne lokalne (stos) - typowo adresy maleja:" << endl;
    cout << "  &a   = " << &a << endl;
    cout << "  &b   = " << &b << endl;
    cout << "  &c   = " << &c << endl;

    cout << "\nElementy tablicy - adresy zawsze rosna o sizeof(int) = "
         << sizeof(int) << ":" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "  &tab[" << i << "] = " << &tab[i] << endl;
    }

    cout << "\nZmienne globalne/statyczne (segment .data) - typowo rosna:" << endl;
    cout << "  &globalna1 = " << &globalna1 << endl;
    cout << "  &globalna2 = " << &globalna2 << endl;

    return 0;
}
