#include <iostream>
#include "../include/WorkExampleOne.h"

int main() {
    std::cout << "kcpp working example" << std::endl;

    WorkExampleOne workExampleOne;
    workExampleOne.run();  // calls class's run flow
    workExampleOne.work(); // direct call to another method

    return 0;
}