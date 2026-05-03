#include <iostream>
#include <string>
#include "ZadKsztalt.h"

using namespace std;

static void rysujTrojkat(int wysokosc) {
    for (int i = 1; i <= wysokosc; ++i) {
        for (int s = 0; s < wysokosc - i; ++s) cout << ' ';
        for (int g = 0; g < 2 * i - 1; ++g) cout << '*';
        cout << '\n';
    }
}

static void rysujPiramideLiczb(int wysokosc) {
    for (int i = 1; i <= wysokosc; ++i) {
        for (int s = 0; s < wysokosc - i; ++s) cout << "  ";
        for (int g = 0; g < i; ++g) cout << i << ' ';
        cout << '\n';
    }
}

int ZadKsztalt::main(int argc, char* argv[]) {
    int h = 5;
    if (argc >= 2) h = stoi(argv[1]);
    if (h < 1) h = 1;

    cout << "Trojkat rownoramienny (wysokosc = " << h << "):\n";
    rysujTrojkat(h);

    cout << "\nPiramida z liczb (wysokosc = " << h << "):\n";
    rysujPiramideLiczb(h);

    return 0;
}
