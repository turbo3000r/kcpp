#include "Launcher.h"

#include <iostream>
#include <string>
using namespace std;

int main() {
    Launcher launcher;
    cout << "=============================\n";
    cout << "  С++ Workspace Launcher\n";
    cout << "=============================\n";
    while (true) {
        cout << "Available tasks:\n";
        cout << "-----------------------------\n";
        for (const auto& projectName : launcher.getProjectNames()) {
            cout << projectName << "\n";
        }
        cout << "-----------------------------\n";
        cout << "Enter task name (or 'q' to quit): ";

        string taskName;
        getline(cin, taskName);
        if (!taskName.empty() && taskName.back() == '\r') {
            taskName.pop_back();
        }

        if (taskName == "q" || taskName == "Q") {
            cout << "Goodbye.\n";
            return 0;
        }

        string args;
        return launcher.run(taskName, args);
    }
}
