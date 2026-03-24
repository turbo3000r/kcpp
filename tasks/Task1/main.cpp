#include "MathUtils.h"

#include <cstdlib>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::vector<int> numbers;
    for (int i = 1; i < argc; ++i) {
        numbers.push_back(std::atoi(argv[i]));
    }

    int sum = calculateSum(numbers);
    std::cout << "Sum: " << sum << "\n";
    return 0;
}
