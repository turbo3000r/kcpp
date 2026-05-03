#include <iostream>
#include <cmath>
#include "ZadPrzeciazaniePotega.h"

using namespace std;

int potega(int podstawa, int wykladnik) {
    int wynik = 1;
    int abs_w = wykladnik < 0 ? -wykladnik : wykladnik;
    for (int i = 0; i < abs_w; ++i) {
        wynik *= podstawa;
    }
    return wykladnik < 0 ? 0 : wynik;
}

double potega(double podstawa, int wykladnik) {
    double wynik = 1.0;
    int abs_w = wykladnik < 0 ? -wykladnik : wykladnik;
    for (int i = 0; i < abs_w; ++i) {
        wynik *= podstawa;
    }
    return wykladnik < 0 ? 1.0 / wynik : wynik;
}

double potega(double podstawa, double wykladnik) {
    return pow(podstawa, wykladnik);
}

int ZadPrzeciazaniePotega::main() {
    cout << "1) potega(int 2, int 10) = " << potega(2, 10) << endl;
    cout << "2) potega(double 2.5, int 3) = " << potega(2.5, 3) << endl;
    cout << "3) potega(double 2.0, double 0.5) = " << potega(2.0, 0.5) << endl;
    return 0;
}
