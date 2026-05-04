#include <iostream>
#include "ZadClass.h"

using namespace std;

Pojazd::Pojazd(const string& marka, int rokProdukcji)
    : markaPubliczna_(marka),
      rokProdukcji_(rokProdukcji),
      przebiegKm_(0),
      silnikUruchomiony_(false) {
}

void Pojazd::uruchomSilnik() {
    silnikUruchomiony_ = true;
    cout << markaPubliczna_ << ": silnik uruchomiony." << endl;
}

void Pojazd::diagnostyka() const {
    cout << "Diagnostyka pojazdu:" << endl;
    cout << "  marka (public)    = " << markaPubliczna_ << endl;
    cout << "  rok   (protected) = " << rokProdukcji_  << endl;
    cout << "  przebieg (private)= " << przebiegKm_    << " km" << endl;
    cout << "  silnik (private)  = " << (silnikUruchomiony_ ? "wlaczony" : "wylaczony")
         << endl;
}

Samochod::Samochod(const string& marka, int rok, const string& model)
    : Pojazd(marka, rok), model_(model) {
}

void Samochod::pokazSzczegoly() const {
    cout << "Samochod " << markaPubliczna_       // public  - OK
         << " " << model_
         << ", rok " << rokProdukcji_            // protected - OK z klasy pochodnej
         << endl;

    // Linia ponizej NIE skompilowalaby sie - 'przebiegKm_' jest private:
    // cout << przebiegKm_ << endl;
}

int ZadClass::main() {
    Pojazd p("Volvo", 2018);
    p.przedstawSie();
    p.uruchomSilnik();
    p.diagnostyka();

    cout << "\nrok (przez inline get): " << p.getRok() << endl;

    cout << "\n--- klasa pochodna ---" << endl;
    Samochod s("Toyota", 2022, "Yaris");
    s.przedstawSie();
    s.pokazSzczegoly();
    s.diagnostyka();

    return 0;
}
