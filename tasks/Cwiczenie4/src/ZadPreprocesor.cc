#include <iostream>
#include <string>
#include "ZadPreprocesor.h"

using namespace std;

#define WLACZ_TRYB_DEBUG

#ifdef WLACZ_TRYB_DEBUG
    #define DBG(x) cout << "[DEBUG] " << x << endl
#else
    #define DBG(x) ((void)0)
#endif

#ifndef MAX_BUFOR
    #define MAX_BUFOR 64
#endif

#define KWADRAT(x)        ((x) * (x))
#define MAX(a, b)         ((a) > (b) ? (a) : (b))

// Stringizacja '#' i klejenie tokenow '##'.
#define NAZWA_ZMIENNEJ(x) (#x)
#define POLACZ(a, b)      a##b

static int kwadratFunc(int x) {
    return x * x;
}
static int maxFunc(int a, int b) {
    return a > b ? a : b;
}

int ZadPreprocesor::main() {
    cout << "=== #ifdef / #ifndef ===" << endl;
#ifdef WLACZ_TRYB_DEBUG
    cout << "WLACZ_TRYB_DEBUG jest zdefiniowane -> komunikaty DBG aktywne." << endl;
#else
    cout << "WLACZ_TRYB_DEBUG nie jest zdefiniowane." << endl;
#endif

#ifndef WLACZ_TRYB_RELEASE
    cout << "WLACZ_TRYB_RELEASE NIE jest zdefiniowane (#ifndef)." << endl;
#endif

    DBG("przyklad komunikatu debug, value=" << 42);

    cout << "\n=== (a) makra vs funkcje ===" << endl;
    int x = 5;
    cout << "Makro KWADRAT(5)         = " << KWADRAT(x) << endl;
    cout << "Funkcja kwadratFunc(5)   = " << kwadratFunc(x) << endl;

    cout << "Makro MAX(3, 7)          = " << MAX(3, 7) << endl;
    cout << "Funkcja maxFunc(3, 7)    = " << maxFunc(3, 7) << endl;

    // Pulapka makra: argument wykonuje sie wielokrotnie:
    int y = 4;
    int wynikMakro = KWADRAT(++y);  // ++y rozwija sie dwukrotnie
    cout << "KWADRAT(++y) = " << wynikMakro
         << "  (y = " << y << " - inkrementowane WIELE razy!)" << endl;

    int z = 4;
    int wynikFunc = kwadratFunc(++z);  // ++z liczy sie raz
    cout << "kwadratFunc(++z) = " << wynikFunc
         << "  (z = " << z << " - inkrementowane RAZ)" << endl;

    cout << "\n=== (b) operatory # i ## ===" << endl;
    int wartosc = 123;
    cout << "Stringizacja: NAZWA_ZMIENNEJ(wartosc) = \""
         << NAZWA_ZMIENNEJ(wartosc) << "\"" << endl;

    int POLACZ(licz, nik) = 7;  // -> int licznik = 7;
    cout << "Klejenie tokenow: POLACZ(licz, nik) -> licznik = " << licznik << endl;

    cout << "MAX_BUFOR = " << MAX_BUFOR << endl;

    return 0;
}
