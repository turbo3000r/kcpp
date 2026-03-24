#include "Launcher.h"

#include <iostream>
#include <string>

int main() {
    std::cout << "=============================\n";
    std::cout << "  Homework Workspace Launcher\n";
    std::cout << "=============================\n";
    std::cout << "Available tasks:\n";
    std::cout << "  Task1  - Sum of integers\n";
    std::cout << "  Task2  - Shape polymorphism\n";
    std::cout << "  Task3  - JSON parsing\n";
    std::cout << "-----------------------------\n";
    std::cout << "Enter task name (or 'q' to quit): ";

    std::string taskName;
    std::getline(std::cin, taskName);
    if (!taskName.empty() && taskName.back() == '\r') {
        taskName.pop_back();
    }

    if (taskName == "q" || taskName == "Q") {
        std::cout << "Goodbye.\n";
        return 0;
    }

    Launcher launcher(taskName);
    return launcher.run();
}
