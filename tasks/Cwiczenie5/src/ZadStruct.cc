#include <iostream>
#include "ZadStruct.h"

using namespace std;

void Osoba::przedstawSie() const {
    cout << "  " << imie << " " << nazwisko << ", lat " << wiek << endl;
}

int ZadStruct::main() {
    cout << "=== Punkt2D - inicjalizacja na rozne sposoby ===" << endl;

    Punkt2D a;                            // pola niezainicjalizowane (smieci) - tylko deklaracja
    a.x = 1.5;                            // pozniejsze przypisanie
    a.y = 2.5;
    cout << "a (po recznym przypisaniu): (" << a.x << ", " << a.y << ")" << endl;

    Punkt2D b = {3.0, 4.0};               // agregatowa inicjalizacja klasyczna
    cout << "b = {3, 4}: (" << b.x << ", " << b.y << ")" << endl;

    Punkt2D c{5.0, 6.0};                  // brace-init (C++11)
    cout << "c{5, 6}: (" << c.x << ", " << c.y << ")" << endl;

    Punkt2D d = c;                        // kopia
    d.x = 99.0;                           // zmiana wartosci - oryginal nietkniety
    cout << "d (kopia c, x=99): (" << d.x << ", " << d.y << ")" << endl;
    cout << "c po modyfikacji d: (" << c.x << ", " << c.y << ") -- bez zmian" << endl;

    cout << "\n=== Struktura z metoda ===" << endl;
    Osoba o = {"Anna", "Kowalska", 27};
    o.przedstawSie();

    cout << "Zmiana wieku w o..." << endl;
    o.wiek = 28;
    o.przedstawSie();

    cout << "\nW C++ struct rozni sie od class wlasciwie tylko domyslnym\n"
         << "poziomem dostepu (public dla struct, private dla class) -\n"
         << "oba moga miec konstruktory, metody i dziedziczenie." << endl;

    return 0;
}
