#include "../include/argumentparser.h"

ArgumentParser::ArgumentParser(int argc, char *argv[]) : argc(argc), argv(argv) {}

bool ArgumentParser::isArgumentPresent(char **flags)
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

