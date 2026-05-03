#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "ZadStringStream.h"

using namespace std;

int ZadStringStream::main() {
    cout << "=== stringstream: budowanie napisu ===" << endl;
    ostringstream out;
    int wiek = 27;
    double waga = 72.5;
    string imie = "Anna";
    out << "Osoba: " << imie << ", wiek: " << wiek << ", waga: " << waga << " kg";
    string zbudowany = out.str();
    cout << "Zbudowany napis: \"" << zbudowany << "\"" << endl;

    cout << "\n=== stringstream: parsowanie napisu ===" << endl;
    string dane = "42 3.14 Hello 7";
    istringstream in(dane);
    int liczba; double pi; string slowo; int koniec;
    in >> liczba >> pi >> slowo >> koniec;
    cout << "  liczba = " << liczba << endl;
    cout << "  pi     = " << pi << endl;
    cout << "  slowo  = " << slowo << endl;
    cout << "  koniec = " << koniec << endl;

    cout << "\n=== stringstream: rozdzielanie po slowach ===" << endl;
    string zdanie = "Programowanie obiektowe w jezyku C++ jest interesujace";
    istringstream split(zdanie);
    vector<string> slowa;
    for (string s; split >> s; ) slowa.push_back(s);
    cout << "Liczba slow: " << slowa.size() << endl;
    for (size_t i = 0; i < slowa.size(); ++i) {
        cout << "  [" << i << "] = " << slowa[i] << endl;
    }

    cout << "\n=== stringstream: konwersja int <-> string ===" << endl;
    int n = 1234;
    stringstream ss;
    ss << n;
    string napis = ss.str();
    cout << "int " << n << " -> string \"" << napis << "\"" << endl;

    string tekst = "987";
    int liczbaZTekstu;
    stringstream(tekst) >> liczbaZTekstu;
    cout << "string \"" << tekst << "\" -> int " << liczbaZTekstu << endl;

    return 0;
}
