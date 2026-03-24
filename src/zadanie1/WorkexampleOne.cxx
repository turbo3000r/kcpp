#include "WorkExampleOne.h"
#include <iostream>

void WorkExampleOne::work() {
    std::cout << "WorkExampleOne is working" << std::endl;
}

void WorkExampleOne::run() {
    std::cout << "WorkExampleOne is running" << std::endl;
    work();
}

WorkExampleOne::WorkExampleOne() {
    std::cout << "WorkExampleOne is constructed" << std::endl;
}

WorkExampleOne::~WorkExampleOne() {
    std::cout << "WorkExampleOne is destructed" << std::endl;
}