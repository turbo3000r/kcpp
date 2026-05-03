#ifndef ZADSTUDENT_H
#define ZADSTUDENT_H

#include <string>
#include <vector>

struct Student {
    std::string imie;
    std::string nazwisko;
    int indeks;
};

class ZadStudent {
    public:
        int main();

    private:
        std::vector<Student> studenci_;

        bool dodaj(const Student& s);
        bool usun(int indeks);
        void wyswietl() const;
        void sortujAlfabetycznie();
        const Student* znajdz(int indeks) const;
};

#endif // ZADSTUDENT_H
