#include <vector>
#include <limits>

#include "../include/argumentvalidator.h"
#include "../include/utils.h"

ArgumentValidator::ArgumentValidator() {}

bool ArgumentValidator::validateAlgorithm(const char *algorithm)
{
    return validate(validAlgorithms, algorithm);
}

bool ArgumentValidator::validateTimeFormat(const char *timeFormat)
{
    return validate(validTimeFormats, timeFormat);
}

bool ArgumentValidator::validateInterval(std::string &interval)
{
    if (interval.front() != '[' || interval.back() != ']')
        return false;

    std::vector<std::string> numbers = utils::split(interval.substr(1, interval.size() - 2), ',');

    if (numbers.size() != 2)
        return false;

    std::string number1_str = numbers[0];
    std::string number2_str = numbers[1];
    if (number1_str.front() == '-' || number2_str.front() == '-')
        return false;

    unsigned int number1 = std::stoi(number1_str);
    unsigned int number2 = std::stoi(number2_str);
    if (number1 < 0 || number2 < 0 || number1 > std::numeric_limits<unsigned int>::max() || number2 > std::numeric_limits<unsigned int>::max())
        return false;

    return true;
}

bool ArgumentValidator::validateMode(const char *mode)
{
    return validate(validModes, mode);
}

bool ArgumentValidator::validateOutputFile(const char *outputFile)
{
    const char *extension = strrchr(outputFile, '.');
    if (extension == nullptr || strcmp(extension, ".txt") != 0)
    {
        return false;
    }

    return true;
}

bool ArgumentValidator::validate(const char **validArguments, const char *argument)
{
    int i = 0;
    while (validArguments[i] != "")
    {
        if (strcmp(validArguments[i], argument) == 0)
        {
            return true;
        }
        i++;
    }

    return false;
}