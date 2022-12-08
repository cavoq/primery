#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

#include <iostream>
#include <cstring>
#include "config.h"

class ArgumentParser
{

public:
    ArgumentParser();
    bool parse(int argc, char *argv[], Config &config);
    void printHelp();

private:
    bool isHelpArgumentPresent();
    bool setConfig(Config &config);
    std::pair<unsigned int, unsigned int> extractIntervalValues(std::string &interval);

    bool isArgumentPresent(const char **flags);
    const char *getArgument(const char *flag);
    const char *getArgument(const char **flags);
    const char *getPresentFlag(const char **flags);

private:
    int argc;
    char **argv;

    const char *intervalFlags[3] = {"-i", "--interval", ""};
    const char *outputFlags[3] = {"-o", "--output", ""};
    const char *helpFlags[3] = {"-h", "--help", ""};
    const char *timeFormatFlags[3] = {"-t", "--time", ""};
    const char *modeFlags[3] = {"-m", "--mode", ""};
};

#endif // ARGUMENTPARSER_H