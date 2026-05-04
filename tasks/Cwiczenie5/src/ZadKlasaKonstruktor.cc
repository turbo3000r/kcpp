#include <iostream>
#include "ZadKlasaKonstruktor.h"

using namespace std;

// Domyslny konstruktor - inicjalizacja "standardowa" (przypisania w ciele).
Ksiazka::Ksiazka() {
    tytul_ = "(brak tytulu)";
    autor_ = "(nieznany)";
    rok_   = 0;
    liczbaStron_ = 0;
    cout << "  [ctor() ] Ksiazka utworzona domyslnie." << endl;
}

// Konstruktor z argumentami - inicjalizacja przez LISTE INICJALIZACYJNA.
// Zalety: jedyny sposob inicjalizacji pol const, referencji, klas bazowych
// i pol-skladnikow nie posiadajacych konstruktora domyslnego; jednokrotne
// wywolanie konstruktora pola zamiast "konstruktor domyslny + przypisanie".
Ksiazka::Ksiazka(const string& tytul, const string& autor, int rok)
    : tytul_(tytul),
      autor_(autor),
      rok_(rok),
      liczbaStron_(100) {
    cout << "  [ctor(...)] Ksiazka \"" << tytul_ << "\" utworzona przez liste inicjalizacyjna." << endl;
}

Ksiazka::~Ksiazka() {
    cout << "  [dtor   ] Ksiazka \"" << tytul_ << "\" zniszczona." << endl;
}

void Ksiazka::wypisz() const {
    cout << "    \"" << tytul_ << "\" - " << autor_
         << ", rok " << rok_ << ", stron: " << liczbaStron_ << endl;
}

int ZadKlasaKonstruktor::main() {
    cout << "Tworzenie obiektow w roznych formach:\n" << endl;

    cout << "[1] Ksiazka k1; (konstruktor domyslny)" << endl;
    Ksiazka k1;
    k1.wypisz();

    cout << "\n[2] Ksiazka k2(\"Pan Tadeusz\", \"Mickiewicz\", 1834);" << endl;
    Ksiazka k2("Pan Tadeusz", "Mickiewicz", 1834);
    k2.wypisz();

    cout << "\n[3] Ksiazka k3{\"Lalka\", \"Prus\", 1890}; (brace-init)" << endl;
    Ksiazka k3{"Lalka", "Prus", 1890};
    k3.wypisz();

    cout << "\n[4] Ksiazka k4 = Ksiazka(\"Quo Vadis\", \"Sienkiewicz\", 1896);" << endl;
    Ksiazka k4 = Ksiazka("Quo Vadis", "Sienkiewicz", 1896);
    k4.wypisz();

    cout << "\nKoniec funkcji - destruktory wywolywane w odwrotnej kolejnosci:" << endl;
    return 0;
}
