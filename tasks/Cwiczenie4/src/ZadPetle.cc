#include <iostream>
#include "ZadPetle.h"

using namespace std;

void ZadPetle::petlaWhile() {
    cout << "=== while + i++/++i ===" << endl;

    int i = 0;
    cout << "while (i < 5) z i++:" << endl;
    while (i < 5) {
        cout << "  i = " << i << endl;
        i++;
    }

    int j = 0;
    cout << "while (j < 5) z ++j (i continue na nieparzystych): " << endl;
    while (j < 5) {
        ++j;
        if (j % 2 != 0) {
            continue;
        }
        cout << "  j (parzyste) = " << j << endl;
    }

    cout << "while z break gdy k == 3:" << endl;
    int k = 0;
    while (true) {
        if (k == 3) break;
        cout << "  k = " << k << endl;
        ++k;
    }
}

void ZadPetle::petlaDoWhile() {
    cout << "\n=== do-while + i++/++i ===" << endl;

    int i = 0;
    cout << "do-while z i++ (do i < 3):" << endl;
    do {
        cout << "  i = " << i << endl;
        i++;
    } while (i < 3);

    int j = 0;
    cout << "do-while z ++j (do j < 3):" << endl;
    do {
        cout << "  j = " << j << endl;
        ++j;
    } while (j < 3);
}

static int wczesneZakonczenie() {
    for (int i = 0; i < 100; ++i) {
        if (i == 4) {
            cout << "  return przy i=" << i << endl;
            return i;
        }
    }
    return -1;
}

void ZadPetle::petlaFor() {
    cout << "\n=== for ===" << endl;
    cout << "for klasyczny:" << endl;
    for (int i = 0; i < 5; ++i) {
        if (i == 2) continue;
        if (i == 4) break;
        cout << "  i = " << i << endl;
    }

    cout << "for z return (przerwanie funkcji): ";
    int v = wczesneZakonczenie();
    cout << "  zwrocono " << v << endl;
}

int ZadPetle::main() {
    petlaWhile();
    petlaDoWhile();
    petlaFor();
    return 0;
}
