#include <iostream>
#include <string>
//#include <fstream>      // do operacji na plikach
#include "ZadCinCoutFile.h"

using namespace std;

int ZadCinCoutFile::main() {
    cout << "=== cout: zapis na ekran (stdout) ===" << endl;
    cout << "To jest komunikat informacyjny na strumieniu cout." << endl;

    cout << "\n=== clog: strumien zapisu komunikatow (buforowany) ===" << endl;
    clog << "To jest komunikat 'log' (clog)." << endl;

    cout << "\n=== cerr: strumien bledow (niebuforowany) ===" << endl;
    cerr << "To jest komunikat bledu (cerr) - kolor moze byc inny w terminalu." << endl;

    cout << "\n=== cin: odczyt z klawiatury ===" << endl;
    cout << "Podaj swoje imie (Enter aby pominac): ";
    string imie;
    if (getline(cin, imie) && !imie.empty()) {
        cout << "Witaj, " << imie << "!" << endl;
    } else {
        cout << "Pomijam etap odczytu z cin." << endl;
    }

    /*
    // -----------------------------------------------------------------
    // Zapis i odczyt do/z pliku - zostawione jako komentarz wg zadania.
    // -----------------------------------------------------------------
    ofstream ofs("dane.txt");
    if (ofs) {
        ofs << "Linia 1\n";
        ofs << "Linia 2\n";
        ofs.close();
    }
    ifstream ifs("dane.txt");
    string linia;
    while (getline(ifs, linia)) {
        cout << "Z pliku: " << linia << endl;
    }
    */

    return 0;
}
