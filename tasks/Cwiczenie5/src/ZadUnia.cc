#include <iostream>
#include <cstdint>
#include <cstring>
#include "ZadUnia.h"

using namespace std;

// Wszystkie pola unii dziela TEN SAM obszar pamieci - sizeof(union) =
// sizeof najwiekszego pola (z wyrownaniem). Zapis jednego pola "psuje"
// pozostale, bo dane nakladaja sie bit po bicie.

union Liczba {
    int i;
    float f;
    char bajty[4];
};

union LiczbaIBajty {
    uint32_t u;
    uint8_t  b[sizeof(uint32_t)];
};

int ZadUnia::main() {
    cout << "=== Podstawowa unia: int / float / bajty ===" << endl;
    cout << "sizeof(Liczba) = " << sizeof(Liczba) << " (rozmiar najwiekszego pola)" << endl;

    Liczba u;
    u.i = 1065353216;  // bitowy odpowiednik float 1.0f wedlug IEEE 754
    cout << "Po u.i = 1065353216:" << endl;
    cout << "  u.i = " << u.i << endl;
    cout << "  u.f = " << u.f << "  (interpretacja tych samych bitow jako float)" << endl;

    u.f = 3.14f;
    cout << "Po u.f = 3.14f:" << endl;
    cout << "  u.f = " << u.f << endl;
    cout << "  u.i = " << u.i << "  (BLAD: int tu juz NIE jest 'logicznie' poprawny -" << endl
         << "         to po prostu interpretacja bitow float jako int)" << endl;

    cout << "\n=== Niebezpieczenstwa unii ===" << endl;
    cout << "1) Tylko jedno pole jest jednoczesnie 'aktywne'." << endl;
    cout << "   Odczyt z innego pola niz ostatnio zapisane to formalnie" << endl;
    cout << "   undefined behaviour w C++ (poza przypadkami trywialnych typow)." << endl;
    cout << "2) W C++ pola typow nietrywialnych (std::string itp.) wymagaja" << endl;
    cout << "   recznego wywolywania konstruktorow / destruktorow (placement new)." << endl;
    cout << "3) Kolejnosc bajtow zalezy od endianness procesora." << endl;

    cout << "\n=== Endianness przez unie ===" << endl;
    LiczbaIBajty lb;
    lb.u = 0x11223344;
    cout << "lb.u = 0x11223344, kolejne bajty (od &b[0]):" << endl;
    for (size_t i = 0; i < sizeof(lb.b); ++i) {
        cout << "  b[" << i << "] = 0x";
        cout.width(2);
        cout.fill('0');
        cout << hex << static_cast<int>(lb.b[i]) << dec << endl;
    }
    cout.fill(' ');
    bool littleEndian = (lb.b[0] == 0x44);
    cout << "Procesor jest "
         << (littleEndian ? "little-endian" : "big-endian / inne") << endl;

    cout << "\n=== Klasyczny blad: zmiana pola psuje pozostale ===" << endl;
    Liczba p;
    p.i = 0x41424344;     // 'A','B','C','D' (little-endian)
    cout << "p.i = 0x41424344, p.bajty = '"
         << p.bajty[0] << p.bajty[1] << p.bajty[2] << p.bajty[3] << "'" << endl;
    p.bajty[0] = 'Z';
    cout << "Po p.bajty[0] = 'Z': p.i = 0x" << hex << p.i << dec
         << "  -- wartosc int sie zmienila bo to ten sam obszar pamieci!" << endl;

    return 0;
}
