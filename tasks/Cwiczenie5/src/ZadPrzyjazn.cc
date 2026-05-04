#include <iostream>
#include "ZadPrzyjazn.h"

using namespace std;

A::A(int sekret) : prywatnyA_(sekret) {}

// W tej metodzie probowalibysmy odczytac b.prywatneB_ - kompilator
// zaprotestuje, bo A nie jest przyjacielem B. Linia jest celowo
// zakomentowana, abysmy mogli skompilowac caly program.
void A::probujCzytacB(const B& /*b*/) const {
    // cout << b.prywatneB_;  // <- BLAD KOMPILACJI: 'prywatneB_' is private
    cout << "[A] Nie moge zajrzec do prywatnych pol B - A nie jest przyjacielem B."
         << endl;
}

B::B(const string& haslo) : prywatneB_(haslo) {}

// B jest jawnie zaprzyjazniony z A wiec ma dostep do A::prywatnyA_.
void B::pokazSekretA(const A& a) const {
    cout << "[B] Mam dostep do prywatnego pola A: prywatnyA_ = "
         << a.prywatnyA_ << endl;
}

int ZadPrzyjazn::main() {
    A a(42);
    B b("tajne haslo");

    cout << "Pokazanie ze B (przyjaciel A) ma dostep do prywatnych pol A:" << endl;
    b.pokazSekretA(a);

    cout << "\nPokazanie ze A NIE ma symetrycznego dostepu do prywatnych pol B:" << endl;
    a.probujCzytacB(b);

    cout << "\nWniosek: przyjazn w C++ nie jest wzajemna ani przechodnia." << endl;
    cout << "Aby A miala dostep do prywatnych pol B, w klasie B trzeba" << endl;
    cout << "dodatkowo zadeklarowac 'friend class A'." << endl;

    return 0;
}
