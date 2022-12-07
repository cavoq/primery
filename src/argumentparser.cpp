#include "../include/argumentparser.h"

ArgumentParser::ArgumentParser(int argc, char *argv[]) : argc(argc), argv(argv) {}

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

char *ArgumentParser::getArgument(char *flag)
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

bool ArgumentParser::isHelpArgumentPresent()
{
    const char *flags[] = {"-h", "--help", ""};
    return isArgumentPresent(flags);
}

bool ArgumentParser::isOutputArgumentPresent()
{
    const char *flags[] = {"-o", "--output", ""};
    return isArgumentPresent(flags);
}

void ArgumentParser::printHelp()
{
    std::cout << "Usage: prime-generator [Options] {algorithm}" << "\n" << std::endl;
    std::cout << "SUPPORTED ALGORITHMS:" << std::endl;
    std::cout << "    { trialDivision, td }" << std::endl;
    std::cout << "    { sieveOfEratosthenes, soe}" << std::endl;
    std::cout << "OPTIONS:" << std::endl;
    std::cout << "    -h, --help: Get help for the program" << std::endl;
    std::cout << "    -o, --output: Specify an output file for the generated prime numbers" << std::endl;
    std::cout << "    -t, --time: Specify time format [ns, ms, s]" << std::endl;
    std::cout << "    -i, --interval: Specify interval to generate prime numbers in format [start, end]" << std::endl;
}