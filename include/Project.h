#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>
using namespace std;

class Project {
public:
    bool init( const string& name);
    int run(string& args) const;
    string getName() const;
    string getExecutablePath() const;
    string getInputFilePath() const;

private:
    string name_;
    string executablePath_;
    string inputFilePath_;
    string getLaunchArgs() const;
};



#if !defined(PROJECT_BINARY_DIR) || !defined(PROJECT_SOURCE_DIR)
#error PROJECT_BINARY_DIR and PROJECT_SOURCE_DIR must be defined
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
static constexpr const char* EXE_EXT = ".exe";
#else
static constexpr const char* EXE_EXT = "";
#endif


#endif // PROJECT_H