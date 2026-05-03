#include <iostream>
#include <iomanip>
#include "ZadTemperaturaFormat.h"

using namespace std;

int ZadTemperaturaFormat::main() {
    cout << right << setw(6) << "Celsjusz"
         << "   " << setw(10) << "Fahrenheit" << endl;
    cout << right << setw(6) << "-------"
         << "   " << setw(10) << "---------" << endl;

    cout << fixed << setprecision(2);
    for (int c = -10; c <= 10; c += 5) {
        double f = c * 9.0 / 5.0 + 32.0;
        cout << right << setw(6) << c
             << "   " << setw(10) << f << endl;
    }

    cout.unsetf(ios::floatfield);
    return 0;
}
