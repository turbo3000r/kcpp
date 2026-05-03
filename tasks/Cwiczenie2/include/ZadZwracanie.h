#ifndef ZADZWRACANIE_H
#define ZADZWRACANIE_H

#include <iostream>
#include <string>
using namespace std;

int zwrocPrzezWartosc(int liczba);
int& zwrocPrzezReferencje(int& liczba);
int* zwrocPrzezWskaznik(int* liczba);
int* zwrocTablice();

class ZadZwracanie {
    public:
        int main();
};

#endif // ZADZWRACANIE_H