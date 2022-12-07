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

    std::string getOutputArgument();
    std::string getTimeFormatArgument();
    std::string getAlgorithm();
    std::pair<unsigned int, unsigned int> getIntervalArgument();

private:
    bool isHelpArgumentPresent();
    void setOutputArgument();
    void setTimeFormatArgument();
    void setIntervalArgument();
    void setAlgorithm();
    std::pair<unsigned int, unsigned int> extractIntervalValues();

    bool isArgumentPresent(const char **flags);
    const char *getArgument(const char *flag);
    const char *getPresentFlag(const char **flags);
    void setArgument(const char **flags, std::string &argument);

private:
    int argc;
    char **argv;

    const char *intervalFlags[3] = {"-i", "--interval", ""};
    const char *outputFlags[3] = {"-o", "--output", ""};
    const char *helpFlags[3] = {"-h", "--help", ""};
    const char *timeFormatFlags[3] = {"-t", "--time", ""};

    std::string interval = "[0,1000]";
    std::string timeFormat = "ms";
    std::string algorithm = "";
    std::string outputFile = "primes.txt";
};

#endif // ARGUMENTPARSER_H