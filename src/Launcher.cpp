using namespace std;

#include "Launcher.h"

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>

Launcher::Launcher() {
    projects_ = loadProjects();
}

int Launcher::run(const string& projectName, string& args) const {
    if (projects_.find(projectName) == projects_.end()) {
        cerr << "Project " << projectName << " not found" << endl;
        return 1;
    }
    return projects_.at(projectName).run(args);
}
map<string, Project> Launcher::loadProjects() const {
    map<string, Project> projects;
    string base = string(PROJECT_SOURCE_DIR);
    string path = base + "/tasks";
    for (const auto& entry : filesystem::directory_iterator(path)) {
        if (entry.is_directory()) {
            string projectName = entry.path().filename().string();
            Project project;
            if (project.init(projectName)) {
                projects[projectName] = project;
            }
        }
    }
    return projects;
}

vector<string> Launcher::getProjectNames() const {
    vector<string> projectNames;
    for (const auto& project : projects_) {
        projectNames.push_back(project.first);
    }
    return projectNames;
}