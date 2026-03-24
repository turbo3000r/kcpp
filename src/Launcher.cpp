#include "Launcher.h"

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

#if defined(_WIN32) || defined(__CYGWIN__)
static constexpr const char* EXE_EXT = ".exe";
#else
static constexpr const char* EXE_EXT = "";
#endif

#ifdef __CYGWIN__
static std::string toNativePath(const std::string& path) {
    if (path.size() >= 2 && path[1] == ':') {
        char drive = static_cast<char>(std::tolower(static_cast<unsigned char>(path[0])));
        return "/cygdrive/" + std::string(1, drive) + path.substr(2);
    }
    return path;
}
#else
static std::string toNativePath(const std::string& path) { return path; }
#endif

Launcher::Launcher(const std::string& taskName)
    : taskName_(taskName) {}

std::string Launcher::buildExecutablePath() const {
    std::string base = toNativePath(PROJECT_BINARY_DIR);
    return base + "/tasks/" + taskName_ + "/" + BUILD_TYPE + "/" + taskName_ + EXE_EXT;
}

std::string Launcher::readInputFile() const {
    std::string base = toNativePath(PROJECT_SOURCE_DIR);
    std::string path = base + "/tasks/" + taskName_ + "/in.txt";

    std::ifstream ifs(path);
    if (!ifs.is_open()) {
        std::cerr << "Warning: could not open " << path << "\n";
        return {};
    }

    std::ostringstream content;
    content << ifs.rdbuf();
    return stripNewlines(content.str());
}

std::string Launcher::stripNewlines(const std::string& text) {
    std::string result;
    result.reserve(text.size());
    for (char ch : text) {
        if (ch != '\n' && ch != '\r') {
            result += ch;
        }
    }
    return result;
}

int Launcher::run() const {
    std::string exePath = buildExecutablePath();
    std::string args = readInputFile();
    std::cout << "PROJECT_BINARY_DIR" << PROJECT_BINARY_DIR << "\n";
    std::string command = exePath;
    if (!args.empty()) {
        command += " " + args;
    }

    std::cout << "Executing: " << command << "\n\n";

    int exitCode = std::system(command.c_str());
    if (exitCode != 0) {
        std::cerr << "\nTask " << taskName_
                  << " exited with code " << exitCode << "\n";
    }
    return exitCode;
}
