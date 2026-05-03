#include <iostream>
#include "ZadPrzeciazaniePole.h"

using namespace std;

const double PI = 3.14159265358979323846;

double pole(double bok) {
    return bok * bok;
}

double pole(double a, double b) {
    return a * b;
}

double pole(int promien) {
    return PI * promien * promien;
}

int ZadPrzeciazaniePole::main() {
    cout << "1) Pole kwadratu (bok=4.0): " << pole(4.0) << endl;
    cout << "2) Pole prostokata (a=3.0, b=5.0): " << pole(3.0, 5.0) << endl;
    cout << "3) Pole kola (promien=2): " << pole(2) << endl;
    return 0;
}
