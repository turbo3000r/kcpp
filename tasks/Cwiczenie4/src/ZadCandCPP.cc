#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <string>
#include "ZadCandCPP.h"

using namespace std;

int ZadCandCPP::main() {
    cout << "=== Te same operacje w stylu C i C++ ===" << endl;

    cout << "\n[1] Wypisanie tekstu i liczby:" << endl;
    int n = 42;
    double pi = 3.14159;
    printf("    C  : n = %d, pi = %.3f\n", n, pi);
    cout << "    C++: n = " << n << ", pi = " << fixed << setprecision(3)
         << pi << endl;
    cout.unsetf(ios::floatfield);

    cout << "\n[2] Wypisanie liczby w hex z wypelnieniem:" << endl;
    int h = 255;
    printf("    C  : 0x%04X\n", h);
    cout << "    C++: 0x" << hex << uppercase << setw(4) << setfill('0')
         << h << dec << nouppercase << setfill(' ') << endl;

    cout << "\n[3] Konkatenacja napisow:" << endl;
    char c1[64] = "Ala ";
    const char* c2 = "ma kota";
    strcat(c1, c2);
    printf("    C  : %s\n", c1);

    string s1 = "Ala ";
    string s2 = "ma kota";
    string s3 = s1 + s2;
    cout << "    C++: " << s3 << endl;

    cout << "\n[4] Dlugosc napisu:" << endl;
    printf("    C  : strlen = %zu\n", strlen(c1));
    cout << "    C++: size   = " << s3.size() << endl;

    return 0;
}
