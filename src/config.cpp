#include "../include/config.h"
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
    if (strcmp(algorithm, "td") == 0)
        return;
    if (strcmp(algorithm, "soe") == 0)
        this->algorithm = "sieveOfEratosthenes";
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
    if (strcmp(timeFormat, "ms") == 0)
        return;
    if (strcmp(timeFormat, "ns") == 0)
        this->timeFormat = "nanoseconds";
    if (strcmp(timeFormat, "s") == 0)
        this->timeFormat = "seconds";
}

std::string &Config::getOutputFile()
{
    return outputFile;
}

void Config::setOutputFile(const char *outputFile)
{
    this->outputFile = outputFile;
}