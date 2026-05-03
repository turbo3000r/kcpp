#include "Launcher.h"

#include <iostream>
#include <string>
#include "utils.h"
using namespace std;


int main() {
    Launcher launcher;
    cout << "=============================\n";
    cout << "  С++ Workspace Launcher\n";
    cout << "=============================\n";
    while (true) {
        cout << "Available tasks:\n";
        cout << "-----------------------------\n";
        for (int i = 0; i < launcher.getProjectNames().size(); i++) {
            cout << i << " - " << launcher.getProjectNames()[i] << "\n";
        }
        cout << "-----------------------------\n";
        cout << "Enter task index (or -1 to quit): ";

        int taskIndex;
        string args;
        proceedTaskLine(taskIndex, args);
        printf("taskIndex: %d\n", taskIndex);
        if (taskIndex == -1) {
            cout << "Goodbye.\n";
            return 0;
        }
        string taskName = launcher.getProjectNames()[taskIndex];

        if (args.empty()) {
        cout << "Enter arguments (Enter to skip): ";
        getline(cin, args);
            if (!args.empty() && args.back() == '\r') {
                args.pop_back();
            }
        }
        int exitCode = launcher.run(taskName, args);
        if (exitCode != 0) {
            cerr << "Task '" << taskName << "' exited with code " << exitCode << endl;
        } else {
            cout << "Task '" << taskName << "' completed successfully" << endl;
        }
    }
}
