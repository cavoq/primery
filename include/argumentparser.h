#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

class ArgumentParser
{

public:
    ArgumentParser(int argc, char* argv[]);
    bool isHelpArgumentPresent();
    bool isOutputArgumentPresent();
    bool isAlgorithmArgumentPresent();
    bool isTimeArgumentPresent();
    bool isIntervalArgumentPresent();
    const char *getOutputArgument();
    const char *getAlgorithmArgument();
    const char *getTimeArgument();
    bool isIntervalArgumentPresent();
    std::pair<unsigned int, unsigned int> getIntervalArgument();

private:
    bool isArgumentPresent(char **flags);

private:
    int argc;
    char** argv;
};

#endif // ARGUMENTPARSER_H