#include <iostream>
#include "ZadArytmetykaWskaznikowZamiana.h"

using namespace std;

void zamien(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int ZadArytmetykaWskaznikowZamiana::main() {
    int x = 5;
    int y = 42;

    cout << "Przed zamiana: x = " << x << ", y = " << y << endl;
    zamien(&x, &y);
    cout << "Po zamianie:   x = " << x << ", y = " << y << endl;

    return 0;
}
