#include "../include/argumentparser.h"

ArgumentParser::ArgumentParser(int argc, char *argv[]) : argc(argc), argv(argv) {}

void ArgumentParser::parseArguments()
{
    if (isHelpArgumentPresent() || argc < 2)
    {
        printHelp();
        return;
    }
    setIntervalArgument();
    setOutputArgument();
    setTimeFormatArgument();
    setAlgorithm();
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

void ArgumentParser::setArgument(const char **flags, std::string &argument)
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

std::pair<unsigned int, unsigned int> ArgumentParser::extractIntervalValues()
{   
    size_t startPos = interval.find_first_of('[') + 1;
    size_t endPos = interval.find_first_of(']');
    size_t seperatorPos = interval.find_first_of(',');
    std::string startStr = interval.substr(startPos, seperatorPos - startPos);
    std::string endStr = interval.substr(seperatorPos + 1, endPos -1 - seperatorPos);
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

std::string ArgumentParser::getTimeFormatArgument()
{
    return timeFormat;
}

void ArgumentParser::setOutputArgument()
{
    setArgument(outputFlags, outputFile);
}

std::string ArgumentParser::getOutputArgument()
{
    return outputFile;
}

void ArgumentParser::setIntervalArgument()
{
    setArgument(intervalFlags, interval);
}

std::pair<unsigned int, unsigned int> ArgumentParser::getIntervalArgument()
{
    return extractIntervalValues();
}

void ArgumentParser::setAlgorithm()
{
    algorithm = argv[argc - 1];
}

std::string ArgumentParser::getAlgorithm()
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
    std::cout << algorithm << "\n";
    std::cout << timeFormat << "\n";
    std::cout << outputFile << std::endl;
}