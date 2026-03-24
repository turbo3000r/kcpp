#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <string>

class Launcher {
public:
    explicit Launcher(const std::string& taskName);
    int run() const;

private:
    std::string taskName_;

    std::string buildExecutablePath() const;
    std::string readInputFile() const;
    static std::string stripNewlines(const std::string& text);
};

#endif // LAUNCHER_H
