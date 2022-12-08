#include "../include/utils.h"

std::vector<unsigned int> utils::generateArray(unsigned int start, unsigned int end)
{
    std::vector<unsigned int> array;

    for (unsigned int i = start; i <= end; i++)
    {
        array.push_back(i);
    }

    return array;
}

std::string utils::mapString(const std::string &input, const std::map<std::string, std::string> &map, const std::string &defaultValue)
{
    if (map.count(input) > 0)
    {
        return map.at(input);
    }
    else
    {
        return defaultValue;
    }
}