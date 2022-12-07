#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

#include <iostream>
#include <cstring>

class ArgumentParser
{

public:
    ArgumentParser(int argc, char *argv[]);
    void parseArguments();
    void debug();
    void printHelp();

    const char *getOutputArgument();
    const char *getTimeArgument();
    std::pair<unsigned int, unsigned int> getIntervalArgument();

private:
    bool isHelpArgumentPresent();
    void setOutputArgument();
    void setTimeArgument();
    void setIntervalArgument();
    std::pair<unsigned int, unsigned int> extractIntervalValues(const std::string &argument);

    bool isArgumentPresent(const char **flags);
    const char *getArgument(const char *flag);
    const char *getPresentFlag(const char **flags);
    void setArgument(const char **flags, const char *argument);

private:
    int argc;
    char **argv;

    const char *intervalFlags[3] = {"-i", "--interval", ""};
    const char *outputFlags[3] = {"-o", "--output", ""};
    const char *helpFlags[3] = {"-h", "--help", ""};
    const char *timeFlags[3] = {"-t", "--time", ""};

    std::pair<unsigned int, unsigned int> interval = {0, 1000};
    const char *time = "ms";
    const char *algorithm;
    const char *outputFile = "primes.txt";
};

#endif // ARGUMENTPARSER_H