#include "../include/config.h"
#include "../include/utils.h"
#include <cstring>

Config::Config() {}

void Config::printConfig()
{
    std::cout << "CONFIG: "
              << "\n";
    std::cout << "    Algorithm  : " << algorithm << "\n";
    std::cout << "    Interval   : "
              << "[" << interval.first << "," << interval.second << "]"
              << "\n";
    std::cout << "    Time format: " << timeFormat << "\n";
    std::cout << "    Output file: " << outputFile << "\n";
}

std::string &Config::getAlgorithm()
{
    return algorithm;
}

void Config::setAlgorithm(const char *algorithm)
{
    std::string algorithmStr = algorithm;
    this->algorithm = utils::mapString(algorithmStr, algorithms);
}

void Config::setMode(const char *mode)
{
    std::string modeStr = mode;
    this->mode = utils::mapString(modeStr, timeFormats);
}

std::string &Config::getMode()
{
    return mode;
}

std::pair<unsigned int, unsigned int> &Config::getInterval()
{
    return interval;
}

void Config::setInterval(std::pair<unsigned int, unsigned int> interval)
{
    this->interval = interval;
}

std::string &Config::getTimeFormat()
{
    return timeFormat;
}

void Config::setTimeFormat(const char *timeFormat)
{
    std::string timeFormatStr = timeFormat;
    this->timeFormat = utils::mapString(timeFormatStr, timeFormats);
}

std::string &Config::getOutputFile()
{
    return outputFile;
}

void Config::setOutputFile(const char *outputFile)
{
    this->outputFile = outputFile;
}