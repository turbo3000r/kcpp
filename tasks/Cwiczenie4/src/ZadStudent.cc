#include <iostream>
#include <iomanip>
#include <algorithm>
#include "ZadStudent.h"

using namespace std;

bool ZadStudent::dodaj(const Student& s) {
    if (s.imie.empty() || s.nazwisko.empty()) {
        cerr << "  [walidacja] Imie i nazwisko nie moga byc puste." << endl;
        return false;
    }
    if (znajdz(s.indeks) != nullptr) {
        cerr << "  [walidacja] Student z indeksem " << s.indeks
             << " juz istnieje." << endl;
        return false;
    }
    studenci_.push_back(s);
    return true;
}

bool ZadStudent::usun(int indeks) {
    auto it = remove_if(studenci_.begin(), studenci_.end(),
        [indeks](const Student& s) { return s.indeks == indeks; });
    if (it == studenci_.end()) return false;
    studenci_.erase(it, studenci_.end());
    return true;
}

void ZadStudent::wyswietl() const {
    if (studenci_.empty()) {
        cout << "  (lista pusta)" << endl;
        return;
    }
    cout << "  " << left << setw(15) << "Imie"
         <<        setw(20) << "Nazwisko"
         <<        setw(10) << "Indeks" << endl;
    cout << "  " << string(45, '-') << endl;
    for (const auto& s : studenci_) {
        cout << "  " << left << setw(15) << s.imie
             <<        setw(20) << s.nazwisko
             <<        setw(10) << s.indeks << endl;
    }
}

void ZadStudent::sortujAlfabetycznie() {
    sort(studenci_.begin(), studenci_.end(),
        [](const Student& a, const Student& b) {
            if (a.nazwisko != b.nazwisko) return a.nazwisko < b.nazwisko;
            return a.imie < b.imie;
        });
}

const Student* ZadStudent::znajdz(int indeks) const {
    for (const auto& s : studenci_) {
        if (s.indeks == indeks) return &s;
    }
    return nullptr;
}

int ZadStudent::main() {
    cout << "=== Baza studentow (demo) ===" << endl;

    cout << "\n[1] Dodawanie:" << endl;
    dodaj({"Anna",   "Kowalska",   12345});
    dodaj({"Jan",    "Nowak",      12346});
    dodaj({"Piotr",  "Abacki",     12347});
    dodaj({"",       "Bezimienny", 12348});  // walidacja: puste imie
    dodaj({"Maria",  "Nowak",      12346});  // walidacja: indeks zajety

    cout << "\n[2] Lista:" << endl;
    wyswietl();

    cout << "\n[3] Sortowanie alfabetyczne (po nazwisku):" << endl;
    sortujAlfabetycznie();
    wyswietl();

    cout << "\n[4] Wyszukiwanie:" << endl;
    int szukany = 12346;
    const Student* znaleziony = znajdz(szukany);
    if (znaleziony) {
        cout << "  Indeks " << szukany << " -> " << znaleziony->imie
             << " " << znaleziony->nazwisko << endl;
    } else {
        cout << "  Indeks " << szukany << " -> brak." << endl;
    }

    cout << "\n[5] Usuwanie indeksu " << szukany << ":" << endl;
    cout << "  " << (usun(szukany) ? "usunieto." : "nie znaleziono.") << endl;
    wyswietl();

    return 0;
}
