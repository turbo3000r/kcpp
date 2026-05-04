#ifndef ZADPRZYJAZN_H
#define ZADPRZYJAZN_H

#include <string>
using namespace std;

// Forward-declaration aby B mogl wystapic w 'friend class B' wewnatrz A.
class B;

class A {
    public:
        A(int sekret);

        // Aby pokazac, ze przyjazn nie jest wzajemna - probujemy z A
        // dostac sie do prywatnych pol B. Bez 'friend class A' wewnatrz
        // B taka funkcja zwyczajnie sie NIE skompiluje.
        void probujCzytacB(const B& b) const;

        friend class B;       // klasa B jest przyjacielem A
        // (UWAGA: TO NIE oznacza ze A jest przyjacielem B - przyjazn nie
        // jest symetryczna ani przechodnia.)

    private:
        int prywatnyA_;
};

class B {
    public:
        B(const string& haslo);

        // Klasa B ma 'friend class B' w A wiec moze siegnac do A::prywatnyA_.
        void pokazSekretA(const A& a) const;

    private:
        string prywatneB_;
};

class ZadPrzyjazn {
    public:
        int main();
};

#endif // ZADPRZYJAZN_H
