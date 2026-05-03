#include "ZadStringStream.h"
#include "ZadManipulacjaStrumieniemCout.h"
#include "ZadCinCoutFile.h"
#include "ZadCandCPP.h"
#include "ZadTabelaFormat.h"
#include "ZadTemperaturaFormat.h"
#include "ZadDaneNaukoweFormat.h"
#include "ZadParzysta.h"
#include "ZadParzystaCase.h"
#include "ZadPetle.h"
#include "ZadSwitch.h"
#include "ZadForA.h"
#include "ZadSilnia.h"
#include "ZadKsztalt.h"
#include "ZadWhileA.h"
#include "ZadGra.h"
#include "ZadStudent.h"
#include "ZadPreprocesor.h"

#include <string>
#include <iostream>
using namespace std;

int mapFunctions(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Dostepne parametry:" << endl;
        cout << "4.0  - stringstream (sstream)" << endl;
        cout << "4.1  - manipulatory cout (setw, setprecision, ...)" << endl;
        cout << "4.2  - cout / clog / cerr / cin" << endl;
        cout << "4.3  - te same operacje w C i C++" << endl;
        cout << "4.4  - tabela produktow" << endl;
        cout << "4.5  - tabela konwersji temperatur" << endl;
        cout << "4.6  - stale matematyczne w 3 notacjach" << endl;
        cout << "4.7  - parzysta/nieparzysta (3 sposoby)" << endl;
        cout << "4.8  <wybor> <liczba> - parzysta przez switch" << endl;
        cout << "4.9  - while / do-while / for" << endl;
        cout << "4.10 <slowo> <liczba> - switch po slowie" << endl;
        cout << "4.11 - liczby nieparzyste i podzielne przez 7" << endl;
        cout << "4.12 <n> - silnia + suma silni" << endl;
        cout << "4.13 <wysokosc> - trojkat i piramida liczb" << endl;
        cout << "4.14 - while ze zliczaniem (wczyta liczby; 0 konczy)" << endl;
        cout << "4.15 <latwy|normalny|trudny> - gra w zgadywanie liczby" << endl;
        cout << "4.16 - baza studentow (vector + struct)" << endl;
        cout << "4.17 - dyrektywy preprocesora" << endl;
        return 1;
    }

    string arg = argv[1];
    auto shiftArgs = [&]() {
        for (int i = 1; i < argc - 1; ++i) argv[i] = argv[i + 1];
        argc -= 1;
    };

    if (arg == "4.0")  return ZadStringStream().main();
    if (arg == "4.1")  return ZadManipulacjaStrumieniemCout().main();
    if (arg == "4.2")  return ZadCinCoutFile().main();
    if (arg == "4.3")  return ZadCandCPP().main();
    if (arg == "4.4")  return ZadTabelaFormat().main();
    if (arg == "4.5")  return ZadTemperaturaFormat().main();
    if (arg == "4.6")  return ZadDaneNaukoweFormat().main();
    if (arg == "4.7")  return ZadParzysta().main();
    if (arg == "4.8")  { shiftArgs(); return ZadParzystaCase().main(argc, argv); }
    if (arg == "4.9")  return ZadPetle().main();
    if (arg == "4.10") { shiftArgs(); return ZadSwitch().main(argc, argv); }
    if (arg == "4.11") return ZadForA().main();
    if (arg == "4.12") { shiftArgs(); return ZadSilnia().main(argc, argv); }
    if (arg == "4.13") { shiftArgs(); return ZadKsztalt().main(argc, argv); }
    if (arg == "4.14") return ZadWhileA().main();
    if (arg == "4.15") { shiftArgs(); return ZadGra().main(argc, argv); }
    if (arg == "4.16") return ZadStudent().main();
    if (arg == "4.17") return ZadPreprocesor().main();

    cout << "Nieznana opcja: " << arg << endl;
    return 1;
}

int main(int argc, char* argv[]) {
    return mapFunctions(argc, argv);
}
