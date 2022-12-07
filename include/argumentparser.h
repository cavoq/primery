#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

#include <iostream>
#include <cstring>

class ArgumentParser
{

public:
    ArgumentParser(int argc, char* argv[]);
    void printHelp();
    bool isHelpArgumentPresent();
    bool isOutputArgumentPresent();

private:
    bool isArgumentPresent(const char **flags);
    char *getArgument(char *flag);

private:
    int argc;
    char** argv;
};

#endif // ARGUMENTPARSER_H