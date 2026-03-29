#include "Project.h"
#include <filesystem>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


bool Project::init(const string& name) {
    name_ = name;
    executablePath_ = string(PROJECT_BINARY_DIR) + "/tasks/" + name  + "/" + name + EXE_EXT;
    if (!filesystem::exists(executablePath_)) {
        return false;
    }
    inputFilePath_ = string(PROJECT_SOURCE_DIR) + "/tasks/" + name + "/in.txt";
    if (!filesystem::exists(inputFilePath_)) {
        inputFilePath_.clear();
    }
    return true;
}

string Project::getName() const { return name_; }
string Project::getExecutablePath() const { return executablePath_; }
string Project::getInputFilePath() const { return inputFilePath_; }

string Project::getLaunchArgs() const {
    if (inputFilePath_.empty()) {
        return "";
    }
    ifstream ifs(inputFilePath_);
    if (!ifs.is_open()) {
        return "";
    }
    string content((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
    return content;
}

int Project::run(string& args) const {
    if (args.empty()) {
        args = getLaunchArgs();
    }
    string command = executablePath_ + " " + args;
    cout << "Executing: " << command << "\n\n";
    int exitCode = system(command.c_str());
    if (exitCode != 0) {
        cerr << "\nTask " << name_ << " exited with code " << exitCode << "\n";
    }
    return exitCode;
}