#ifndef ZADENUMEAMPLE_H
#define ZADENUMEAMPLE_H

#include <iostream>
#include <string>
using namespace std;

enum class Month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

class ZadEnumExample {
    public:
        string monthToString(Month month);
        int main();
};

#endif // ZADENUMEAMPLE_H