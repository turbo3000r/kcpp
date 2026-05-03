#ifndef UTILS_H
#define UTILS_H

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

inline void proceedTaskLine(int& taskIndex, string& args) {
    string buffer;
    getline(cin, buffer);

    if (!buffer.empty() && buffer.back() == '\r') {
        buffer.pop_back();
    }

    int consumedChars = 0;
    if (sscanf(buffer.c_str(), "%d%n", &taskIndex, &consumedChars) < 1) {
        taskIndex = -1;
        args.clear();
        return;
    }

    args = buffer.substr(static_cast<size_t>(consumedChars));
    size_t argStart = args.find_first_not_of(" \t");
    args =
        argStart == string::npos ? string() : args.substr(argStart);
}

#endif // UTILS_H