#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <memory>
#include <string>
#include "ZadMetodyAbstrakcyjne.h"

using namespace std;

static const double PI = 3.14159265358979323846;

Figura::Figura(const string& nazwa) : nazwa_(nazwa) {}

const string& Figura::nazwa() const { return nazwa_; }

void Figura::wypisz() const {
    cout << "  " << left << setw(10) << nazwa_
         << "  obwod = " << right << setw(8) << fixed << setprecision(3) << obwod()
         << "   pole = " << right << setw(8) << pole() << endl;
    cout.unsetf(ios::floatfield);
}

Kwadrat::Kwadrat(double bok) : Figura("Kwadrat"), bok_(bok) {}
double Kwadrat::obwod() const { return 4.0 * bok_; }
double Kwadrat::pole()  const { return bok_ * bok_; }

Prostokat::Prostokat(double a, double b) : Figura("Prostokat"), a_(a), b_(b) {}
double Prostokat::obwod() const { return 2.0 * (a_ + b_); }
double Prostokat::pole()  const { return a_ * b_; }

Trojkat::Trojkat(double a, double b, double c)
    : Figura("Trojkat"), a_(a), b_(b), c_(c) {}
double Trojkat::obwod() const { return a_ + b_ + c_; }
double Trojkat::pole() const {
    double s = (a_ + b_ + c_) / 2.0;
    double podPierwiastkiem = s * (s - a_) * (s - b_) * (s - c_);
    return podPierwiastkiem > 0.0 ? sqrt(podPierwiastkiem) : 0.0;
}

Kolo::Kolo(double promien) : Figura("Kolo"), r_(promien) {}
double Kolo::obwod() const { return 2.0 * PI * r_; }
double Kolo::pole()  const { return PI * r_ * r_; }

double Kolo::Dystans(double mKwNaOsobe) const {
    // Modelujemy "strefe" przyslugujaca osobie jako kolo o powierzchni X m^2:
    //   pi * r^2 = X     ->     r = sqrt(X / pi)
    if (mKwNaOsobe <= 0.0) return 0.0;
    return sqrt(mKwNaOsobe / PI);
}

int ZadMetodyAbstrakcyjne::main(int argc, char* argv[]) {
    // Domyslne dane przykladowe.
    Kwadrat   kw(4.0);
    Prostokat pr(3.0, 5.0);
    Trojkat   tr(3.0, 4.0, 5.0);
    Kolo      ko(2.0);

    // Polimorficzny pojemnik wskaznikow do klasy bazowej.
    vector<Figura*> figury = {&kw, &pr, &tr, &ko};

    cout << "Obwod i pole figur (przez wskazniki do klasy abstrakcyjnej Figura):" << endl;
    for (const Figura* f : figury) {
        f->wypisz();
    }

    cout << "\n--- Dystans (metoda specyficzna dla Kola) ---" << endl;

    double mKwNaOsobe = 1.5;  // wartosc domyslna
    if (argc >= 2) {
        try {
            mKwNaOsobe = stod(argv[1]);
        } catch (...) {
            cerr << "Niepoprawny argument, uzywam domyslnej wartosci "
                 << mKwNaOsobe << endl;
        }
    }

    cout << fixed << setprecision(3);
    cout << "Zalozenie: " << mKwNaOsobe
         << " m^2 powierzchni przypada na 1 osobe." << endl;
    cout << "Dystans (promien) do nastepnej osoby = "
         << ko.Dystans(mKwNaOsobe) << " m" << endl;

    cout << "\nPrzyklady dla kilku wartosci X (m^2 / osobe):" << endl;
    double xs[] = {0.5, 1.0, 1.5, 2.0, 4.0, 10.0};
    for (double x : xs) {
        cout << "  X = " << setw(5) << x
             << " m^2  ->  r = " << setw(6) << ko.Dystans(x) << " m" << endl;
    }
    cout.unsetf(ios::floatfield);

    return 0;
}
