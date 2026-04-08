#include <iostream>
#include <string>
#include "ZadStringExample.h"

using namespace std;

int ZadStringExample::main() {
    string text = "Ala ma kota";
    string other = "Programowanie C++";


    cout << "1) empty(): " << boolalpha << text.empty() << endl;

    cout << "2) size(): " << text.size() << ", length(): " << text.length() << endl;

    try {
        cout << "3) at(4): " << text.at(4) << endl;
    } catch (const out_of_range& e) {
        cout << "Wyjatek at(): " << e.what() << endl;
    }

    string tmp = text;
    tmp.clear();
    cout << "4) clear(): \"" << tmp << "\" (size=" << tmp.size() << ")" << endl;


    string erased = text;
    erased.erase(3, 3); // usunie " ma"
    cout << "5) erase(3,3): " << erased << endl;

    size_t pos = text.find("kota");
    if (pos != string::npos) {
        cout << "6) find(\"kota\"): znaleziono na pozycji " << pos << endl;
    } else {
        cout << "6) find(\"kota\"): nie znaleziono" << endl;
    }

    cout << "7) przed swap: text=\"" << text << "\", other=\"" << other << "\"" << endl;
    text.swap(other);
    cout << "   po   swap: text=\"" << text << "\", other=\"" << other << "\"" << endl;

    string sub = text.substr(0, 12);
    cout << "8) substr(0,12): " << sub << endl;

    sub.append(" - to jest podciag");
    cout << "9) append(...): " << sub << endl;

    return 0;
}
