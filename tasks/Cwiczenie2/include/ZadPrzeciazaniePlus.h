#ifndef ZADPRZECIAZANIEPLUS_H
#define ZADPRZECIAZANIEPLUS_H

#include <iostream>
using namespace std;

class Punkt {
    private:
        double x_;
        double y_;
    public:
        Punkt(double x = 0.0, double y = 0.0);
        double getX() const;
        double getY() const;
        Punkt operator+(const Punkt& other) const;
        void print() const;
};

class ZadPrzeciazaniePlus {
    public:
        int main();
};

#endif // ZADPRZECIAZANIEPLUS_H
