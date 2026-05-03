#ifndef ZADPRZEKAZYWANIETABLIC_H
#define ZADPRZEKAZYWANIETABLIC_H

#include <iostream>
#include <cstddef>
using namespace std;

// W C/C++ klasyczne przekazanie tablicy int tab[] -> rozpada sie do wskaznika
// (int*) i tracimy informacje o rozmiarze (sizeof zwraca rozmiar wskaznika).
// Da sie zachowac rozmiar przy przekazywaniu przez referencje do tablicy:
//     void f(int (&tab)[N])
// lub uogolnic to szablonem template<size_t N>.

template <size_t N>
void wypiszTablice(const int (&tab)[N]) {
    cout << "Rozmiar (z szablonu): " << N << ", elementy: ";
    for (size_t i = 0; i < N; ++i) {
        cout << tab[i] << " ";
    }
    cout << endl;
}

template <size_t N>
int sumaTablicy(const int (&tab)[N]) {
    int suma = 0;
    for (size_t i = 0; i < N; ++i) suma += tab[i];
    return suma;
}

class ZadPrzekazywanieTablic {
    public:
        int main();
};

#endif // ZADPRZEKAZYWANIETABLIC_H
