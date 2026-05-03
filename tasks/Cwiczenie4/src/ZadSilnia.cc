#include <iostream>
#include <string>
#include "ZadSilnia.h"

using namespace std;

static unsigned long long silnia(int n) {
    unsigned long long w = 1;
    for (int i = 2; i <= n; ++i) w *= static_cast<unsigned long long>(i);
    return w;
}

int ZadSilnia::main(int argc, char* argv[]) {
    int n = 5;
    if (argc >= 2) {
        n = stoi(argv[1]);
    } else {
        cout << "Nie podano argumentu - przyjmuje n = " << n << endl;
    }

    if (n < 0) {
        cerr << "Blad: silnia jest zdefiniowana tylko dla liczb nieujemnych. "
             << "Podano: " << n << endl;
        return 1;
    }

    cout << n << "! = " << silnia(n) << endl;

    unsigned long long suma = 0;
    cout << "Suma silni od 1 do " << n << ":" << endl;
    for (int i = 1; i <= n; ++i) {
        unsigned long long s = silnia(i);
        cout << "  " << i << "! = " << s << endl;
        suma += s;
    }
    cout << "Suma = " << suma << endl;

    return 0;
}
