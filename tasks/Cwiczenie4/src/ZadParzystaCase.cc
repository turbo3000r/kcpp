#include <iostream>
#include <string>
#include "ZadParzystaCase.h"
#include "ZadParzysta.h"

using namespace std;

int ZadParzystaCase::main(int argc, char* argv[]) {
    int wybor = 1;
    int liczba = 6;

    if (argc >= 2) wybor  = stoi(argv[1]);
    if (argc >= 3) liczba = stoi(argv[2]);

    cout << "wybor = " << wybor << ", liczba = " << liczba << endl;
    bool wynik = false;

    switch (wybor) {
        case 1:
            cout << "[switch] -> wariant bitowy (& 1)" << endl;
            wynik = czyParzystaBitowo(liczba);
            break;
        case 2:
            cout << "[switch] -> wariant modulo (% 2)" << endl;
            wynik = czyParzystaModulo(liczba);
            break;
        case 3:
            cout << "[switch] -> wariant warunkowy (?:)" << endl;
            wynik = czyParzystaWarunkowo(liczba);
            break;
        default:
            cout << "[switch] -> nieznany wybor (uzyj 1, 2, 3). Domyslnie: bitowo." << endl;
            wynik = czyParzystaBitowo(liczba);
            break;
    }

    cout << liczba << (wynik ? " jest parzysta" : " jest nieparzysta") << endl;
    return 0;
}
