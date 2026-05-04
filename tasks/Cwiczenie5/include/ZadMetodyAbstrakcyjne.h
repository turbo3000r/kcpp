#ifndef ZADMETODYABSTRAKCYJNE_H
#define ZADMETODYABSTRAKCYJNE_H

#include <string>
using namespace std;

class Figura {
    public:
        explicit Figura(const string& nazwa);
        virtual ~Figura() = default;

        virtual double obwod() const = 0;
        virtual double pole()  const = 0;

        const string& nazwa() const;
        void wypisz() const;

    protected:
        string nazwa_;
};

class Kwadrat : public Figura {
    public:
        explicit Kwadrat(double bok);
        double obwod() const override;
        double pole()  const override;
    private:
        double bok_;
};

class Prostokat : public Figura {
    public:
        Prostokat(double a, double b);
        double obwod() const override;
        double pole()  const override;
    private:
        double a_;
        double b_;
};

class Trojkat : public Figura {
    public:
        Trojkat(double a, double b, double c);   // 3 boki
        double obwod() const override;
        double pole()  const override;            // wzor Herona
    private:
        double a_, b_, c_;
};

class Kolo : public Figura {
    public:
        explicit Kolo(double promien);
        double obwod() const override;
        double pole()  const override;

        // Dystans: promien okregu o polu rownym X (m^2 na osobe).
        // Innymi slowy odleglosc, w jakiej moze stanac kolejna osoba,
        // jesli kazdej przysluguje X metrow kwadratowych powierzchni
        // (modelujac przestrzen wokol osoby jako kolo).
        double Dystans(double mKwNaOsobe) const;

    private:
        double r_;
};

class ZadMetodyAbstrakcyjne {
    public:
        int main(int argc = 0, char* argv[] = nullptr);
};

#endif // ZADMETODYABSTRAKCYJNE_H
