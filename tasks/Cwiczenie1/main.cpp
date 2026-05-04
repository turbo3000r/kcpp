#include "ZadEnumExample.h"
#include "ZadClassExample.h"
#include "ZadCharExample.h"
#include "ZadStringExample.h"
#include "ZadMainExample.h"

#include <string>
#include <iostream>
using namespace std;

int mapFunctions(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Dostepne parametry:" << endl;
        cout << "1.0 - Zadanie 1.0 (enum z miesiacami)" << endl;
        cout << "1.1 - Zadanie 1.1 (klasa - jeden plik)" << endl;
        cout << "1.2 - Zadanie 1.2 (funkcje cstring / cctype)" << endl;
        cout << "1.3 - Zadanie 1.3 (operacje na std::string)" << endl;
        cout << "1.4 <funkcja...> - Zadanie 1.4 (funkcja main + extern C)" << endl;
        return 1;
    }

    string arg = argv[1];
    if (arg == "1.0") {
        return ZadEnumExample().main();
    } else if (arg == "1.1") {
        return ZadClassExample().main();
    } else if (arg == "1.2") {
        return ZadCharExample().main();
    } else if (arg == "1.3") {
        return ZadStringExample().main();
    } else if (arg == "1.4") {
        for (int i = 1; i < argc - 1; ++i) argv[i] = argv[i + 1];
        argc -= 1;
        return ZadMainExample().main(argc, argv);
    } else {
        cout << "Nieznana opcja: " << arg << endl;
        return 1;
    }
}

int main(int argc, char* argv[]) {
    return mapFunctions(argc, argv);
}
