#ifndef ZADSTRUCTKONSTRUKTOR_H
#define ZADSTRUCTKONSTRUKTOR_H

#include <string>
using namespace std;

struct Adres {
    string ulica;
    string miasto;
    int kodPocztowy;

    Adres();                                              // domyslny konstruktor
    Adres(const string& ulica, const string& miasto, int kp);  // z argumentami
    ~Adres();                                             // destruktor

    void wypisz() const;
};

class ZadStructKonstruktor {
    public:
        int main();
};

#endif // ZADSTRUCTKONSTRUKTOR_H
