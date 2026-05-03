#include <iostream>
#include "ZadArytmetykaWskaznikowTabliceB.h"

using namespace std;

int ZadArytmetykaWskaznikowTabliceB::main() {
    const int N = 5;
    double t1[N];
    double t2[N];
    double t3[N];

    cout << "Podaj " << N << " liczb zmiennoprzecinkowych dla pierwszej tablicy:" << endl;
    for (double* p = t1; p < t1 + N; ++p) {
        if (!(cin >> *p)) {
            cerr << "Blad odczytu liczby." << endl;
            return 1;
        }
    }

    for (double *src = t1, *dst = t2; src < t1 + N; ++src, ++dst) {
        *dst = (*src) * 2.0;
    }

    for (double *a = t1, *b = t2, *s = t3; a < t1 + N; ++a, ++b, ++s) {
        *s = *a + *b;
    }

    cout << "\nT1 (wejsciowa):     ";
    for (const double* p = t1; p < t1 + N; ++p) cout << *p << " ";
    cout << "\nT2 (T1 * 2):        ";
    for (const double* p = t2; p < t2 + N; ++p) cout << *p << " ";
    cout << "\nT3 (T1 + T2):       ";
    for (const double* p = t3; p < t3 + N; ++p) cout << *p << " ";
    cout << endl;

    return 0;
}
