#include <iostream>
#include <string>
#include "ZadMainExample.h"

using namespace std;

void greet() {
    cout << "greet(): Witaj w ZadMainExample!" << endl;
}

void showLength(const string& text) {
    cout << "showLength(): Dlugosc napisu = " << text.size() << endl;
}

void showFirstChar(const string& text) {
    if (text.empty()) {
        cout << "showFirstChar(): Napis jest pusty." << endl;
        return;
    }
    cout << "showFirstChar(): Pierwszy znak = '" << text.at(0) << "'" << endl;
}

extern "C" { 
    void cFunctionOne() {
        cout << "cFunctionOne(): Funkcja zadeklarowana jako extern \"C\"." << endl;
    }
    void cFunctionTwo() {
        cout << "cFunctionTwo(): Druga funkcja extern \"C\"." << endl;
    }
}

int ZadMainExample::main(int argc, char* argv[]) {
    const string sampleText = "Hello, World!";

    if (argc == 1) {
        cout << "Brak argumentow. Dostepne opcje:" << endl;
        cout << "  greet first length c1 c2 all" << endl;
        cout << "Przyklad: ZadMainExample.cc greet c1 length" << endl;
        return 0;
    }

    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];

        if (arg == "greet") {
            greet();
        } else if (arg == "first") {
            showFirstChar(sampleText);
        } else if (arg == "length") {
            showLength(sampleText);
        } else if (arg == "c1") {
            cFunctionOne();
        } else if (arg == "c2") {
            cFunctionTwo();
        } else if (arg == "all") {
            greet();
            showFirstChar(sampleText);
            showLength(sampleText);
            cFunctionOne();
            cFunctionTwo();
        } else {
            cout << "Nieznany argument: " << arg << endl;
        }
    }

    return 0;
}