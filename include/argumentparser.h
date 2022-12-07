#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

#include <iostream>
#include <cstring>

class ArgumentParser
{

public:
    ArgumentParser(int argc, char* argv[]);
    bool parseArguments();
    void debug();
    void printHelp();
    bool isHelpArgumentPresent();
    bool isOutputArgumentPresent();
    bool isIntervalArgumentPresent();
    std::pair<unsigned int, unsigned int> getIntervalArgument();

private:
    bool isArgumentPresent(const char **flags);
    const char *getArgument(const char *flag);
    const char *getPresentFlag(const char **flags);
    std::pair<unsigned int, unsigned int> extractIntervalValues(const std::string &argument);

private:
    int argc;
    char** argv;
};

#endif // ARGUMENTPARSER_H