#include <iostream>
#include "ZadStructKonstruktor.h"

using namespace std;

// Struktura w C++ moze miec konstruktory tak samo jak klasa.
// Rozni je tylko domyslny poziom dostepu (struct = public, class = private).

Adres::Adres() {
    // inicjalizacja standardowa (przypisania w ciele)
    ulica = "(nieznana)";
    miasto = "(nieznane)";
    kodPocztowy = 0;
    cout << "  [ctor() ] Adres utworzony domyslnie." << endl;
}

Adres::Adres(const string& u, const string& m, int kp)
    : ulica(u),                  // lista inicjalizacyjna
      miasto(m),
      kodPocztowy(kp) {
    cout << "  [ctor(...)] Adres utworzony lista inicjalizacyjna: " << ulica << ", " << miasto << endl;
}

Adres::~Adres() {
    cout << "  [dtor   ] Adres \"" << ulica << ", " << miasto << "\" zniszczony." << endl;
}

void Adres::wypisz() const {
    cout << "    " << ulica << ", " << kodPocztowy << " " << miasto << endl;
}

int ZadStructKonstruktor::main() {
    cout << "Tworzenie obiektow struktury Adres:\n" << endl;

    cout << "[1] Adres a1; (konstruktor domyslny)" << endl;
    Adres a1;
    a1.wypisz();

    cout << "\n[2] Adres a2(\"Krakowska 12\", \"Krakow\", 30001);" << endl;
    Adres a2("Krakowska 12", "Krakow", 30001);
    a2.wypisz();

    cout << "\n[3] Adres a3{\"Wawelska 5\", \"Warszawa\", 02034}; (brace-init)" << endl;
    Adres a3{"Wawelska 5", "Warszawa", 2034};
    a3.wypisz();

    cout << "\n[4] Adres a4 = Adres(\"Glowna 1\", \"Gdansk\", 80001);" << endl;
    Adres a4 = Adres("Glowna 1", "Gdansk", 80001);
    a4.wypisz();

    cout << "\nKoniec - destruktory zostana wywolane:" << endl;
    return 0;
}
