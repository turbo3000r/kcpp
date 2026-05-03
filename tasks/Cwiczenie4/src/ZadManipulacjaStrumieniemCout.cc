#include <iostream>
#include <iomanip>
#include "ZadManipulacjaStrumieniemCout.h"

using namespace std;

int ZadManipulacjaStrumieniemCout::main() {
    cout << "=== Demonstracja manipulatorow strumienia cout ===" << endl;

    int liczba = 42;
    double wartosc = 3.14159265358979;

    cout << "\n[1] setw + setfill - prawe wyrownanie i wypelnienie '*':" << endl;
    cout << "    |" << setw(10) << setfill('*') << liczba << "|" << endl;
    cout << "    |" << setw(10) << setfill(' ') << liczba << "| (z powrotem spacje)" << endl;

    cout << "\n[2] left / right:" << endl;
    cout << "    |" << left  << setw(10) << "abc" << "|" << endl;
    cout << "    |" << right << setw(10) << "abc" << "|" << endl;

    cout << "\n[3] setprecision + fixed/scientific:" << endl;
    cout << "    domyslnie:    " << wartosc << endl;
    cout << "    setprec(3):   " << setprecision(3) << wartosc << endl;
    cout << "    fixed:        " << fixed << setprecision(4) << wartosc << endl;
    cout << "    scientific:   " << scientific << wartosc << endl;
    cout.unsetf(ios::floatfield);
    cout << setprecision(6);

    cout << "\n[4] hex / dec / oct + showbase:" << endl;
    cout << showbase;
    cout << "    dec:  " << dec << 255 << endl;
    cout << "    hex:  " << hex << 255 << endl;
    cout << "    oct:  " << oct << 255 << endl;
    cout << dec << noshowbase;

    cout << "\n[5] boolalpha:" << endl;
    cout << "    domyslnie: " << true << " / " << false << endl;
    cout << "    boolalpha: " << boolalpha << true << " / " << false
         << noboolalpha << endl;

    // ----------------------------------------------------------------
    //  Wymagana tabelka - wartosci wynikaja z prawdziwych obliczen.
    // ----------------------------------------------------------------
    cout << "\n=== Tabelka wyjsciowa wymagana w zadaniu ===" << endl;

    double a  = 12.345;
    double b  = 1.2345;
    double c  = 1.2345;
    double T1 = 1.234;
    double T2 = 12.34567;
    double T3 = 12.345678;

    double avg  = (a + b + c) / 3.0;
    double Tavg = (T1 + T2 + T3) / 3.0;

    cout << string(50, '=') << endl;
    cout << "Wynika naszego dzialania: " << setprecision(5) << avg
         << " jest niepoprawny ale:" << endl;

    cout << fixed;
    cout << "   output:  " << setw(7) << setprecision(3) << a
         << "    T: "      << setw(5) << setprecision(3) << T1 << endl;
    cout << "   output1: " << setw(7) << setprecision(4) << b
         << "    T: "      << setw(8) << setprecision(5) << T2 << endl;
    cout << "   output2: " << setw(7) << setprecision(4) << c
         << "    T: "      << setw(9) << setprecision(6) << T3 << endl;
    cout << "   ---------------------------------" << endl;
    cout << "   average: " << setw(7) << setprecision(4) << avg
         << "    T: "      << setw(9) << setprecision(6) << Tavg << endl;
    cout << string(50, '=') << endl;

    cout.unsetf(ios::floatfield);
    return 0;
}
