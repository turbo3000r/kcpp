#ifndef ZADCLASS_H
#define ZADCLASS_H

#include <iostream>
#include <string>
using namespace std;

// Klasa bazowa - aby pokazac dostep do skladnikow protected przez klase
// pochodna, rzeczywisty 'protected' musi byc widoczny w hierarchii.
class Pojazd {
    public:
        Pojazd(const string& marka, int rokProdukcji);

        // Metoda zadeklarowana i ZDEFINIOWANA wewnatrz klasy = niejawnie inline.
        void przedstawSie() const {
            cout << "Pojazd: " << markaPubliczna_ << " (rok " << rokProdukcji_ << ")" << endl;
        }

        // Inline jawnie:
        inline int getRok() const { return rokProdukcji_; }

        // Metoda zadeklarowana w klasie, definicja PONIZEJ klasy.
        void uruchomSilnik();

        // Metoda majaca dostep do pol private oraz protected (zwykla metoda
        // skladowa).
        void diagnostyka() const;

    public:
        string markaPubliczna_;       // public  - dostepne wszedzie

    protected:
        int rokProdukcji_;            // protected - widoczne dla klas pochodnych

    private:
        int przebiegKm_;              // private  - tylko wewnatrz tej klasy
        bool silnikUruchomiony_;
};

// Klasa pochodna - moze siegac do skladnikow PROTECTED, ale nie do PRIVATE.
class Samochod : public Pojazd {
    public:
        Samochod(const string& marka, int rok, const string& model);

        void pokazSzczegoly() const;

    private:
        string model_;
};

class ZadClass {
    public:
        int main();
};

#endif // ZADCLASS_H
