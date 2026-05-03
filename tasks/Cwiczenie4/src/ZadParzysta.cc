#include <iostream>
#include "ZadParzysta.h"

using namespace std;

bool czyParzystaBitowo(int n) {
    // Liczba parzysta ma najmlodszy bit = 0, nieparzysta = 1.
    // Operacja n & 1 maskuje wszystkie pozostale bity.
    //
    // Przyklad dla n = 6:
    //     6   = 0000 0110
    //     1   = 0000 0001
    //   6 & 1 = 0000 0000  -> 0  -> parzysta
    //
    // Przyklad dla n = 7:
    //     7   = 0000 0111
    //     1   = 0000 0001
    //   7 & 1 = 0000 0001  -> 1  -> nieparzysta
    return (n & 1) == 0;
}

bool czyParzystaModulo(int n) {
    return (n % 2) == 0;
}

bool czyParzystaWarunkowo(int n) {
    return ((n % 2) ? false : true);
}

int ZadParzysta::main() {
    int liczby[] = {0, 1, 2, 3, 4, 7, 10, -3, -8};

    cout << "  n  | bitowo | modulo | warunkowo" << endl;
    cout << "-----+--------+--------+----------" << endl;
    cout << boolalpha;
    for (int n : liczby) {
        cout << " " << (n < 0 ? "" : " ") << n
             << "  |  "  << czyParzystaBitowo(n)
             << "\t|  "  << czyParzystaModulo(n)
             << "\t|  "  << czyParzystaWarunkowo(n) << endl;
    }
    cout << noboolalpha;
    return 0;
}
