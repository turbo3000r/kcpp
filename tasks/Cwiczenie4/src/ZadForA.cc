#include <iostream>
#include "ZadForA.h"

using namespace std;

int ZadForA::main() {
    cout << "Liczby nieparzyste w przedziale 1..30:" << endl;
    for (int i = 1; i <= 30; ++i) {
        if (i % 2 != 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    cout << "Liczby podzielne przez 7 w przedziale 1..100:" << endl;
    for (int i = 1; i <= 100; ++i) {
        if (i % 7 == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
