#include <iostream>
#include <iomanip>
#include <string>
#include "ZadTabelaFormat.h"

using namespace std;

struct Produkt {
    string nazwa;
    double cena;
    int ilosc;
};

int ZadTabelaFormat::main() {
    Produkt produkty[] = {
        {"Chleb",          4.99,  5},
        {"Mleko",          3.20, 10},
        {"Jajka (10 szt)", 8.50,  3},
    };

    const int W_NAZWA = 15;
    const int W_CENA  = 8;
    const int W_ILOSC = 7;

    cout << "| " << left  << setw(W_NAZWA) << "Nazwa"
         << " | " << right << setw(W_CENA) << "Cena"
         << " | " << right << setw(W_ILOSC) << "Ilosc"
         << " |" << endl;

    cout << "|" << string(W_NAZWA + 2, '-')
         << "|" << string(W_CENA  + 2, '-')
         << "|" << string(W_ILOSC + 2, '-')
         << "|" << endl;

    cout << fixed << setprecision(2);
    for (const auto& p : produkty) {
        cout << "| " << left  << setw(W_NAZWA) << p.nazwa
             << " | " << right << setw(W_CENA) << p.cena
             << " | " << right << setw(W_ILOSC) << p.ilosc
             << " |" << endl;
    }
    cout.unsetf(ios::floatfield);

    return 0;
}
