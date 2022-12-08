#include "../include/argumentparser.h"

ArgumentParser::ArgumentParser() {}

bool ArgumentParser::parse(int argc, char *argv[], Config &config)
{
    this->argc = argc;
    this->argv = argv;

    if (isHelpArgumentPresent() || argc < 2 || !setConfig(config))
    {
        printHelp();
        return false;
    }
    return true;
}

bool ArgumentParser::setConfig(Config &config)
{
    if (isArgumentPresent(intervalFlags))
    {
        std::string intervalArgument = getArgument(intervalFlags);
        if (intervalArgument == "")
            return false;
        config.setInterval(extractIntervalValues(intervalArgument));
    }
    if (isArgumentPresent(outputFlags))
    {
        const char *outputArgument = getArgument(outputFlags);
        if (outputArgument == "")
            return false;
        config.setOutputFile(outputArgument);
    }
    if (isArgumentPresent(timeFormatFlags))
    {
        const char *timeFormatArgument = getArgument(timeFormatFlags);
        if (timeFormatArgument == "")
            return false;
        config.setTimeFormat(timeFormatArgument);
    }
    if (isArgumentPresent(modeFlags))
    {
        const char *modeArgument = getArgument(modeFlags);
        if (modeArgument == "")
            return false;
        config.setMode(modeArgument);
    }
    if (argv[argc - 1] == "")
        return false;
    config.setAlgorithm(argv[argc - 1]);

    return true;
}

bool ArgumentParser::isArgumentPresent(const char **flags)
{
    for (int i = 0; i < argc; i++)
    {
        for (int j = 0; flags[j] != ""; j++)
        {
            if (std::string(argv[i]) == flags[j])
            {
                return true;
            }
        }
    }
    return false;
}

const char *ArgumentParser::getArgument(const char **flags)
{
    const char *flag = getPresentFlag(flags);
    const char *argument = getArgument(flag);

    if (strlen(argument) == 0)
        return "";

    return argument;
}

const char *ArgumentParser::getPresentFlag(const char **flags)
{
    for (int i = 0; i < argc; i++)
    {
        for (int j = 0; flags[j] != ""; j++)
        {
            if (std::string(argv[i]) == flags[j])
            {
                return flags[j];
            }
        }
    }
    return NULL;
}

const char *ArgumentParser::getArgument(const char *flag)
{
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], flag) == 0 && i + 1 < argc)
        {
            return argv[i + 1];
        }
    }
    return NULL;
}

std::pair<unsigned int, unsigned int> ArgumentParser::extractIntervalValues(std::string &interval)
{
    size_t startPos = interval.find_first_of('[') + 1;
    size_t endPos = interval.find_first_of(']');
    size_t seperatorPos = interval.find_first_of(',');
    std::string startStr = interval.substr(startPos, seperatorPos - startPos);
    std::string endStr = interval.substr(seperatorPos + 1, endPos - 1 - seperatorPos);
    unsigned int start = std::stoul(startStr);
    unsigned int end = std::stoul(endStr);
    return {start, end};
}

bool ArgumentParser::isHelpArgumentPresent()
{
    return isArgumentPresent(helpFlags);
}

void ArgumentParser::printHelp()
{
    std::cout << "Usage: ./prime-generator [Options] {algorithm}"
              << "\n"
              << std::endl;
    std::cout << "SUPPORTED ALGORITHMS:" << std::endl;
    std::cout << "    { trialDivision, td }" << std::endl;
    std::cout << "    { sieveOfEratosthenes, soe}" << std::endl;
    std::cout << "    { sieveOfSundaram, sos}" << std::endl;
    std::cout << "OPTIONS:" << std::endl;
    std::cout << "    -h, --help: Get help for the program" << std::endl;
    std::cout << "    -o, --output: Specify an output file for the generated prime numbers (default is primes.txt)" << std::endl;
    std::cout << "    -m, --mode: Specify an output file for the generated prime numbers [single, parallel] (default is single)" << std::endl;
    std::cout << "    -t, --time: Specify time format [ns, ms, s] (default is milliseconds)" << std::endl;
    std::cout << "    -i, --interval: Specify interval to generate prime numbers in format [start,end] (default is [2, 1000]" << std::endl;
}