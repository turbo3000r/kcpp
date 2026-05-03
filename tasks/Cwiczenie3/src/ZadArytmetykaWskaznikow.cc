#include <iostream>
#include "ZadArytmetykaWskaznikow.h"

using namespace std;

// -----------------------------------------------------------------------------
// Funkcja1 - omowienie wybranych operacji na wskaznikach.
//
// p++       : post-inkrementacja wskaznika - wyrazenie ma wartosc starego p,
//             ale po operacji p wskazuje na NASTEPNY element.
// ++p       : pre-inkrementacja wskaznika - p przesuwa sie o 1 i wyrazenie
//             ma juz wartosc nowego p.
// ++*p      : pre-inkrementacja WARTOSCI pod p (rownowazne ++(*p)).
//             Wskaznik p nie zmienia sie, zmienia sie *p.
// ++(*p)    : to samo co wyzej - jawne nawiasy podkreslaja, ze inkrementujemy
//             wartosc, a nie wskaznik.
// ++*(p)    : nawiasy wokol p nic nie zmieniaja - to nadal ++(*p).
// *p++      : ze wzgledu na priorytety operatorow rowne *(p++).
//             Najpierw ewaluowane jest p++ (post-inkrementacja wskaznika -
//             wyrazenie ma stara wartosc p), potem dereferencja - czyli
//             dostajemy wartosc ELEMENTU aktualnego, a wskaznik PO operacji
//             pokazuje na nastepny element.
// (*p)++    : post-inkrementacja WARTOSCI pod p. Wskaznik p sie nie zmienia,
//             *p zwiekszane jest o 1 ale wyrazenie zwraca STARA wartosc.
// *(p)++    : to samo co *p++ - nawiasy nie zmieniaja priorytetu unarnego ++.
// *++p      : pre-inkrementacja p i dereferencja - wskaznik przesuwa sie do
//             przodu i odczytujemy nowy element.
// *(++p)    : to samo co *++p - jawne nawiasy.
// -----------------------------------------------------------------------------

void ZadArytmetykaWskaznikow::Funkcja1() {
    cout << "=== Funkcja1: operacje na wskaznikach ===" << endl;
    int tab[5] = {10, 20, 30, 40, 50};
    int* p = tab;

    cout << "Stan poczatkowy: tab = {10, 20, 30, 40, 50}, p = &tab[0]" << endl;

    cout << "\n[1] *p          = " << *p
         << "   (wartosc pod p, p nadal &tab[0])" << endl;

    cout << "[2] *p++        = " << *p++
         << "   (zwraca *(stare p), potem p przesuwa sie do tab[1])" << endl;
    cout << "    teraz *p    = " << *p << " (tab[1])" << endl;

    cout << "[3] *++p        = " << *++p
         << "   (najpierw ++p -> tab[2], potem dereferencja)" << endl;

    cout << "[4] (*p)++      = " << (*p)++
         << "   (zwraca stara wartosc, ale tab[2] zwiekszone do 31)" << endl;
    cout << "    teraz tab[2]= " << tab[2] << endl;

    cout << "[5] ++*p        = " << ++*p
         << "   (++(*p): tab[2] += 1, zwraca nowa wartosc)" << endl;
    cout << "    teraz tab[2]= " << tab[2] << endl;

    cout << "[6] ++(*p)      = " << ++(*p)
         << "   (jawnie ++(*p) - identycznie jak wyzej)" << endl;

    cout << "[7] *(p)++      = " << *(p)++
         << "   (rownowazne *p++, p przesuwa sie do tab[3])" << endl;
    cout << "    teraz *p    = " << *p << " (tab[3] = 40)" << endl;

    cout << "[8] *(++p)      = " << *(++p)
         << "   (rownowazne *++p, p -> tab[4])" << endl;

    cout << "[9] p++         (post-inkrementacja samego wskaznika; *p byloby UB - poza tablica)" << endl;
    p++;

    cout << "[10] ++p        - kolejne przesuniecie wskaznika." << endl;
}

// -----------------------------------------------------------------------------
// Funkcja2 - odtworzenie zadanej tabelki przy uzyciu jednego wskaznika.
// Aby uzyskac przewidywalny rozklad zmiennych a, b, c w pamieci, umieszczamy
// je w tablicy 3-elementowej (gwarantowana ciaglosc) i traktujemy jako alias
// kolejne referencje:  a = abc[0], b = abc[1], c = abc[2].
// Wskaznik p porusza sie po tej tablicy operatorami ++/--, ktore sa typowymi
// elementami arytmetyki wskaznikow.
// -----------------------------------------------------------------------------

static void wypiszStan(int krok, int a, int b, int c) {
    cout << krok << (krok < 10 ? ".  " : ". ") << "A, B, C: "
         << a << "  " << b << "  " << c << endl;
}

void ZadArytmetykaWskaznikow::Funkcja2() {
    cout << "\n=== Funkcja2: tabelka wartosci A, B, C ===" << endl;
    int abc[3] = {0, 0, 0};
    int& a = abc[0];
    int& b = abc[1];
    int& c = abc[2];
    int* p = &abc[0];

    wypiszStan(1, a, b, c);
    *++p = 10; wypiszStan(2, a, b, c);
    *++p = 20; wypiszStan(3, a, b, c);
    *--p = 30; wypiszStan(4, a, b, c);
    *--p = 40; wypiszStan(5, a, b, c);
    *++p = 50; wypiszStan(6, a, b, c);
    *++p = 60; wypiszStan(7, a, b, c);
    *--p = 70; wypiszStan(8, a, b, c);
    *--p = 80; wypiszStan(9, a, b, c);
    *++p = 90; wypiszStan(10, a, b, c);
}

int ZadArytmetykaWskaznikow::main() {
    Funkcja1();
    Funkcja2();
    return 0;
}
