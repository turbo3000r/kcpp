#include <iostream>
#include <iomanip>
#include <string>
#include "ZadDaneNaukoweFormat.h"

using namespace std;

struct Stala {
    string nazwa;
    double wartosc;
};

static void wyrodkuj(const string& tekst, int szerokosc) {
    int padding = szerokosc - static_cast<int>(tekst.size());
    if (padding <= 0) {
        cout << tekst;
        return;
    }
    int lewy = padding / 2;
    int prawy = padding - lewy;
    cout << string(lewy, ' ') << tekst << string(prawy, ' ');
}

int ZadDaneNaukoweFormat::main() {
    Stala stale[] = {
        {"Pi",            3.14159265358979},
        {"e",             2.71828182845904},
        {"Zloty podzial", 1.61803398874989},
    };

    const int W_NAZWA = 15;
    const int W_WART  = 20;

    wyrodkuj("Stala", W_NAZWA);
    cout << " ";
    wyrodkuj("Wartosc (domyslnie)", W_WART);
    cout << " ";
    wyrodkuj("Notacja stala", W_WART);
    cout << " ";
    wyrodkuj("Notacja naukowa", W_WART);
    cout << endl;

    cout << string(W_NAZWA, '-') << " "
         << string(W_WART, '-')  << " "
         << string(W_WART, '-')  << " "
         << string(W_WART, '-')  << endl;

    for (const auto& s : stale) {
        cout << left << setw(W_NAZWA) << s.nazwa << " ";

        cout.unsetf(ios::floatfield);
        cout << left << setw(W_WART) << setprecision(6) << s.wartosc << " ";

        cout << fixed;
        cout << left << setw(W_WART) << setprecision(6) << s.wartosc << " ";

        cout.unsetf(ios::floatfield);
        cout << scientific;
        cout << left << setw(W_WART) << setprecision(6) << s.wartosc;

        cout.unsetf(ios::floatfield);
        cout << endl;
    }

    return 0;
}
