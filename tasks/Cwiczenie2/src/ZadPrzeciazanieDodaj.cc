#include <iostream>
#include <string>
#include "ZadPrzeciazanieDodaj.h"

using namespace std;

int dodaj(int a, int b) {
    return a + b;
}

double dodaj(double a, double b) {
    return a + b;
}

string dodaj(const string& a, const string& b) {
    return a + b;
}

int ZadPrzeciazanieDodaj::main() {
    cout << "1) dodaj(int, int): 3 + 4 = " << dodaj(3, 4) << endl;
    cout << "2) dodaj(double, double): 1.5 + 2.25 = " << dodaj(1.5, 2.25) << endl;
    cout << "3) dodaj(string, string): \"Ala \" + \"ma kota\" = "
         << dodaj(string("Ala "), string("ma kota")) << endl;
    return 0;
}
