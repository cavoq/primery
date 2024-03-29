#include "../include/argumentparser.h"
#include "../include/utils.h"

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
        if (!argumentValidator.validateInterval(intervalArgument))
            return false;

        config.setInterval(extractIntervalValues(intervalArgument));
    }
    if (isArgumentPresent(outputFlags))
    {
        const char *outputArgument = getArgument(outputFlags);
        if (!argumentValidator.validateOutputFile(outputArgument))
            return false;

        config.setOutputFile(outputArgument);
    }
    if (isArgumentPresent(timeFormatFlags))
    {
        const char *timeFormatArgument = getArgument(timeFormatFlags);
        if (!argumentValidator.validateTimeFormat(timeFormatArgument))
            return false;

        config.setTimeFormat(timeFormatArgument);
    }
    if (isArgumentPresent(modeFlags))
    {
        const char *modeArgument = getArgument(modeFlags);
        if (!argumentValidator.validateMode(modeArgument))
            return false;

        config.setMode(modeArgument);
    }
    if (!argumentValidator.validateAlgorithm(argv[argc - 1]))
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
    std::vector<std::string> numbers = utils::split(interval.substr(1, interval.size() - 2), ',');
    unsigned int start = std::stoul(numbers[0]);
    unsigned int end = std::stoul(numbers[1]);
    return {start, end};
}

bool ArgumentParser::isHelpArgumentPresent()
{
    return isArgumentPresent(helpFlags);
}

void ArgumentParser::printHelp()
{
    std::cout << "USAGE: primery [Options] {algorithm}"
              << "\n"
              << std::endl;
    std::cout << "EXAMPLE: primery -i [234,100000] -t ms -m p sieveOfEratosthenes"
              << "\n"
              << std::endl;
    std::cout << "SUPPORTED ALGORITHMS:" << std::endl;
    std::cout << "    { td  | trialDivision }" << std::endl;
    std::cout << "    { soe | sieveOfEratosthenes }" << std::endl;
    std::cout << "    { sos | sieveOfSundaram }" << std::endl;
    std::cout << "    { soa | sieveOfAtkin }"
              << "\n"
              << std::endl;
    std::cout << "OPTIONS:" << std::endl;
    std::cout << "    -h, --help: Get help for the program" << std::endl;
    std::cout << "    -o, --output: Specify an output file for the generated prime numbers (default is primes.txt)" << std::endl;
    std::cout << "    -m, --mode: Specify a mode for generating prime numbers [s | single, p | parallel] (default is single)" << std::endl;
    std::cout << "    -t, --time: Specify time format [ns | nanoseconds, ms | milliseconds, s | seconds] (default is milliseconds)" << std::endl;
    std::cout << "    -i, --interval: Specify interval to generate prime numbers in format [start,end] (default is [2,1000])"
              << "\n"
              << std::endl;
}
