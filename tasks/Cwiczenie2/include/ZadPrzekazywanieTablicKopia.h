#ifndef ZADPRZEKAZYWANIETABLICKOPIA_H
#define ZADPRZEKAZYWANIETABLICKOPIA_H

#include <iostream>
#include <array>
using namespace std;

// W jezyku C/C++ przekazanie tablicy "C-style" (int tab[]) do funkcji
// nie tworzy kopii - rozpada sie do wskaznika do pierwszego elementu.
// Aby przekazac KOPIE tablicy nalezy ja opakowac w klasie/strukturze
// (np. std::array, std::vector lub wlasna strukture). Wtedy obowiazuja
// standardowe reguly kopiowania obiektow.

void zmienKopie(array<int, 5> kopia);
void zmienOryginal(array<int, 5>& referencja);

class ZadPrzekazywanieTablicKopia {
    public:
        int main();
};

#endif // ZADPRZEKAZYWANIETABLICKOPIA_H
