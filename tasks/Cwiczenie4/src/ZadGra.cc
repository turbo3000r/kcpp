#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "ZadGra.h"

using namespace std;

int ZadGra::main(int argc, char* argv[]) {
    int gorny = 100;
    string poziom = "normalny";

    if (argc >= 2) {
        poziom = argv[1];
        if (poziom == "latwy")    gorny = 50;
        else if (poziom == "trudny") gorny = 200;
        else if (poziom == "normalny") gorny = 100;
        else {
            cout << "Nieznany poziom \"" << poziom
                 << "\". Dostepne: latwy / normalny / trudny. Domyslnie: normalny." << endl;
            poziom = "normalny";
        }
    }

    srand(static_cast<unsigned>(time(nullptr)));
    int sekret = (rand() % gorny) + 1;
    int proba = 0;
    const int maxProb = 10;

    cout << "Gra w zgadywanie liczb." << endl;
    cout << "Poziom: " << poziom << " (zakres 1.." << gorny << ")" << endl;
    cout << "Masz " << maxProb << " prob." << endl;

    while (proba < maxProb) {
        cout << "Proba " << (proba + 1) << "/" << maxProb << ": ";
        int wartosc;
        if (!(cin >> wartosc)) {
            cerr << "Niepoprawne wejscie." << endl;
            return 1;
        }
        ++proba;
        if (wartosc == sekret) {
            cout << "Brawo! Zgadles w " << proba << " probach." << endl;
            return 0;
        }
        cout << (wartosc < sekret ? "Za malo." : "Za duzo.") << endl;
    }

    cout << "Niestety, nie zgadles. Prawidlowa liczba to " << sekret << "." << endl;
    return 0;
}
