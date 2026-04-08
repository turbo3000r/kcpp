#ifndef ZADCLASSEXAMPLE_H
#define ZADCLASSEXAMPLE_H

#include <iostream>
#include <string>
using namespace std;

class Car {
    private:
        string plate;
        string fakePlate;
        string color;
    
    public:
        Car(const string& plateValue, const string& fakePlateValue, const string& colorValue);
        ~Car();
        void print() const;
};

class ZadClassExample {
    public:
        int main();
};

#endif // ZADCLASSEXAMPLE_H