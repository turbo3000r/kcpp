#include <iostream>
#include "ZadOperatoryPrzypisania.h"

using namespace std;

void ZadOperatoryPrzypisania::OperatoryArytmetyczne() {
    cout << "=== Operatory arytmetyczne ===" << endl;
    int a = 17;
    int b = 5;

    cout << "a = " << a << ", b = " << b << endl;
    cout << "a + b  = " << (a + b) << endl;
    cout << "a - b  = " << (a - b) << endl;
    cout << "a * b  = " << (a * b) << endl;
    cout << "a / b  = " << (a / b) << "  (dzielenie calkowite)" << endl;
    cout << "a % b  = " << (a % b) << "  (reszta z dzielenia)" << endl;

    int x = 10;
    cout << "\nInkrementacja / dekrementacja (x = 10):" << endl;
    cout << "x++ daje " << x++ << ", po: x = " << x << endl;
    cout << "++x daje " << ++x << ", po: x = " << x << endl;
    cout << "x-- daje " << x-- << ", po: x = " << x << endl;
    cout << "--x daje " << --x << ", po: x = " << x << endl;

    cout << "\nUnarny minus: -a = " << -a << endl;
}

void ZadOperatoryPrzypisania::OperatoryPrzypisania() {
    cout << "\n=== Operatory przypisania ===" << endl;
    int v = 100;

    cout << "Start: v = " << v << endl;
    v = 50;     cout << "v  =  50  -> v = " << v << endl;
    v += 10;    cout << "v +=  10  -> v = " << v << endl;
    v -= 4;     cout << "v -=   4  -> v = " << v << endl;
    v *= 3;     cout << "v *=   3  -> v = " << v << endl;
    v /= 2;     cout << "v /=   2  -> v = " << v << endl;
    v %= 7;     cout << "v %=   7  -> v = " << v << endl;

    cout << "\nOperatory bitowe-przypisania (v = 12 = 0b1100):" << endl;
    v = 12;
    v &= 10;    cout << "v &=  10  -> v = " << v << endl;
    v = 12; v |= 1;     cout << "v |=   1  -> v = " << v << endl;
    v = 12; v ^= 5;     cout << "v ^=   5  -> v = " << v << endl;
    v = 12; v <<= 2;    cout << "v <<=  2  -> v = " << v << endl;
    v = 12; v >>= 1;    cout << "v >>=  1  -> v = " << v << endl;
}

int ZadOperatoryPrzypisania::main() {
    OperatoryArytmetyczne();
    OperatoryPrzypisania();
    return 0;
}
