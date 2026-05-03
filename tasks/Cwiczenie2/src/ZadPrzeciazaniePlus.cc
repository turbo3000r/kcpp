#include <iostream>
#include "ZadPrzeciazaniePlus.h"

using namespace std;

Punkt::Punkt(double x, double y) : x_(x), y_(y) {}

double Punkt::getX() const { return x_; }
double Punkt::getY() const { return y_; }

Punkt Punkt::operator+(const Punkt& other) const {
    return Punkt(x_ + other.x_, y_ + other.y_);
}

void Punkt::print() const {
    cout << "(" << x_ << ", " << y_ << ")";
}

int ZadPrzeciazaniePlus::main() {
    Punkt p1(1.5, 2.5);
    Punkt p2(3.0, -0.5);
    Punkt suma = p1 + p2;

    cout << "p1 = "; p1.print(); cout << endl;
    cout << "p2 = "; p2.print(); cout << endl;
    cout << "p1 + p2 = "; suma.print(); cout << endl;

    return 0;
}
