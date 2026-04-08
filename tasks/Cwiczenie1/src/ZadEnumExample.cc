#include <iostream>
#include <string>
#include "ZadEnumExample.h"


using namespace std;

std::string ZadEnumExample::monthToString(Month month) {
    switch (month) {
        case Month::January: return "January";
        case Month::February: return "February";
        case Month::March: return "March";
        case Month::April: return "April";
        case Month::May: return "May";
        case Month::June: return "June";
        case Month::July: return "July";
        case Month::August: return "August";
        case Month::September: return "September";
        case Month::October: return "October";
        case Month::November: return "November";
        case Month::December: return "December";
        default: return "Unknown";
    }
}

int ZadEnumExample::main() {
    Month current = Month::April;

    cout << "Wybrany miesiac: " << monthToString(current) << endl;
    cout << "Numer miesiaca: " << static_cast<int>(current) << endl;

    return 0;
}
