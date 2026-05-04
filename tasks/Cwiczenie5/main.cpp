#include "ZadClass.h"
#include "ZadStruct.h"
#include "ZadUnia.h"
#include "ZadKlasaKonstruktor.h"
#include "ZadStructKonstruktor.h"
#include "ZadPrzyjazn.h"
#include "ZadMetodyAbstrakcyjne.h"

#include <string>
#include <iostream>
using namespace std;

int mapFunctions(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Dostepne parametry:" << endl;
        cout << "5.1   - klasa: public/private/protected, inline, dziedziczenie" << endl;
        cout << "5.2   - struktury: deklaracja/definicja/operacje" << endl;
        cout << "5.3   - unie: dzialanie i niebezpieczenstwa" << endl;
        cout << "5.4a  - klasa z konstruktorami i destruktorem" << endl;
        cout << "5.4b  - struktura z konstruktorami i destruktorem" << endl;
        cout << "5.5   - przyjazn klas (friend) - czy jest wzajemna?" << endl;
        cout << "5.6 [m^2/osobe] - figury (klasa abstrakcyjna) + Dystans" << endl;
        return 1;
    }

    string arg = argv[1];
    auto shiftArgs = [&]() {
        for (int i = 1; i < argc - 1; ++i) argv[i] = argv[i + 1];
        argc -= 1;
    };

    if (arg == "5.1")   return ZadClass().main();
    if (arg == "5.2")   return ZadStruct().main();
    if (arg == "5.3")   return ZadUnia().main();
    if (arg == "5.4a")  return ZadKlasaKonstruktor().main();
    if (arg == "5.4b")  return ZadStructKonstruktor().main();
    if (arg == "5.5")   return ZadPrzyjazn().main();
    if (arg == "5.6")   { shiftArgs(); return ZadMetodyAbstrakcyjne().main(argc, argv); }

    cout << "Nieznana opcja: " << arg << endl;
    return 1;
}

int main(int argc, char* argv[]) {
    return mapFunctions(argc, argv);
}
