#ifndef ZADSTRUCT_H
#define ZADSTRUCT_H

#include <string>
using namespace std;

struct Punkt2D {
    double x;
    double y;
};

struct Osoba {
    string imie;
    string nazwisko;
    int wiek;
    void przedstawSie() const;
};

class ZadStruct {
    public:
        int main();
};

#endif // ZADSTRUCT_H
