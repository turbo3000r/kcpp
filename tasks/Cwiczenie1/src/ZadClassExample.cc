#include <iostream>
#include <string>
#include "ZadClassExample.h"

using namespace std;

Car::Car(const string& plateValue, const string& fakePlateValue, const string& colorValue)
    : plate(plateValue), fakePlate(fakePlateValue), color(colorValue) {
    cout << "The Car object has been created" << endl;
}

Car::~Car() {
    cout << "The Car object has been destroyed" << endl;
}

void Car::print() const {
    cout << "---------------------------------------" << endl;
    cout << "All about this car:" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Plate No.:     " << plate << endl;
    cout << "FakePlate No.: " << fakePlate << endl;
    cout << "Color:         " << color << endl;
    cout << "---------------------------------------" << endl;
}

int ZadClassExample::main() {
    Car myCar("KR 1234A", "XX 0000X", "Blue");
    myCar.print();
    return 0;
}
