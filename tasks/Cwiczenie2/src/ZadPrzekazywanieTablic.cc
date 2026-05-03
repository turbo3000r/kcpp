#include <iostream>
#include "ZadPrzekazywanieTablic.h"

using namespace std;

int ZadPrzekazywanieTablic::main() {
    int tab1[5] = {1, 2, 3, 4, 5};
    int tab2[8] = {10, 20, 30, 40, 50, 60, 70, 80};

    cout << "Tablica 1:" << endl;
    wypiszTablice(tab1);
    cout << "Suma tablicy 1 = " << sumaTablicy(tab1) << endl;

    cout << "Tablica 2:" << endl;
    wypiszTablice(tab2);
    cout << "Suma tablicy 2 = " << sumaTablicy(tab2) << endl;

    return 0;
}
