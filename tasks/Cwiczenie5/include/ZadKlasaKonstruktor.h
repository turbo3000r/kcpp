#ifndef ZADKLASAKONSTRUKTOR_H
#define ZADKLASAKONSTRUKTOR_H

#include <string>
using namespace std;

class Ksiazka {
    public:
        Ksiazka();                                          // domyslny konstruktor
        Ksiazka(const string& tytul, const string& autor, int rok);  // z argumentami
        ~Ksiazka();                                         // destruktor

        void wypisz() const;

    private:
        string tytul_;
        string autor_;
        int rok_;
        int liczbaStron_;
};

class ZadKlasaKonstruktor {
    public:
        int main();
};

#endif // ZADKLASAKONSTRUKTOR_H
