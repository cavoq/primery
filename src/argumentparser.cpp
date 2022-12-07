#include "../include/argumentparser.h"

ArgumentParser::ArgumentParser(int argc, char *argv[]) : argc(argc), argv(argv) {}

void ArgumentParser::parseArguments()
{
    if (isHelpArgumentPresent() || argc < 2)
    {
        printHelp();
        return;
    }
    setAlgorithm();
    setIntervalArgument();
    setOutputArgument();
    setTimeFormatArgument();
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

void ArgumentParser::setArgument(const char **flags, const char *argument)
{
    if (!isArgumentPresent(flags))
        return;

    const char *presentFlag = getPresentFlag(flags);
    const char *presentArgument = getArgument(presentFlag);

    if (strlen(presentArgument) == 0)
        return;

    argument = presentArgument;
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
    return "";
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
    return "";
}

std::pair<unsigned int, unsigned int> ArgumentParser::extractIntervalValues(const std::string &argument)
{
    size_t startPos = argument.find_first_of('[') + 1;
    size_t endPos = argument.find_first_of(']');
    std::string startStr = argument.substr(startPos, endPos - startPos);
    std::string endStr = argument.substr(endPos + 1);
    unsigned int start = std::stoul(startStr);
    unsigned int end = std::stoul(endStr);
    return {start, end};
}

bool ArgumentParser::isHelpArgumentPresent()
{
    return isArgumentPresent(helpFlags);
}

void ArgumentParser::setTimeFormatArgument()
{
    setArgument(timeFormatFlags, timeFormat);
}

const char *ArgumentParser::getTimeFormatArgument()
{
    return timeFormat;
}

void ArgumentParser::setOutputArgument()
{
    setArgument(outputFlags, outputFile);
}

const char *ArgumentParser::getOutputArgument()
{
    return outputFile;
}

void ArgumentParser::setIntervalArgument()
{
    const char *intervalStr = "";
    setArgument(intervalFlags, intervalStr);
    if (intervalStr == "")
        return;
    interval = extractIntervalValues(intervalStr);
}

std::pair<unsigned int, unsigned int> ArgumentParser::getIntervalArgument()
{
    return interval;
}

void ArgumentParser::setAlgorithm()
{
    algorithm = argv[argc - 1];
}

const char *ArgumentParser::getAlgorithm()
{
    return algorithm;
}

void ArgumentParser::printHelp()
{
    std::cout << "Usage: prime-generator [Options] {algorithm}"
              << "\n"
              << std::endl;
    std::cout << "SUPPORTED ALGORITHMS:" << std::endl;
    std::cout << "    { trialDivision, td }" << std::endl;
    std::cout << "    { sieveOfEratosthenes, soe}" << std::endl;
    std::cout << "OPTIONS:" << std::endl;
    std::cout << "    -h, --help: Get help for the program" << std::endl;
    std::cout << "    -o, --output: Specify an output file for the generated prime numbers" << std::endl;
    std::cout << "    -t, --time: Specify time format [ns, ms, s]" << std::endl;
    std::cout << "    -i, --interval: Specify interval to generate prime numbers in format [start,end]" << std::endl;
}

void ArgumentParser::debug()
{
    std::cout << "Argument Count: " << argc << std::endl;
    std::cout << "Arguments: " << std::endl;
    for (int i = 0; i < argc; i++)
    {
        std::cout << i << ": " << argv[i] << std::endl;
    }
    std::cout << "Set arguuments: " << "\n";
    std::cout << algorithm << "\n";
    std::cout << timeFormat << "\n";
    std::cout << interval.first << interval.second << "\n";
    std::cout << outputFile << "\n";
}