
#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <string>
#include "Project.h"
#include <map>

class Launcher {
public:
    explicit Launcher();
    vector<string> getProjectNames() const;
    int run(const string& projectName, string& args) const;

private:
    map<string, Project> loadProjects() const;
    map<string, Project> projects_;
};


#endif // LAUNCHER_H

