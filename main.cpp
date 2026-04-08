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

        cout << "Enter arguments (Enter to skip): ";
        string args;
        getline(cin, args);
        if (!args.empty() && args.back() == '\r') {
            args.pop_back();
        }
        int exitCode = launcher.run(taskName, args);
        if (exitCode != 0) {
            cerr << "Task '" << taskName << "' exited with code " << exitCode << endl;
        } else {
            cout << "Task '" << taskName << "' completed successfully" << endl;
        }
    }
}
