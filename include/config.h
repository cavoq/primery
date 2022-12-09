#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <map>

class Config
{

public:
    Config();
    void printConfig();
    std::string &getOutputFile();
    std::string &getTimeFormat();
    std::string &getAlgorithm();
    std::string &getMode();
    std::pair<unsigned int, unsigned int> &getInterval();

    void setOutputFile(const char *outputFile);
    void setTimeFormat(const char *timeFormat);
    void setMode(const char *mode);
    void setInterval(std::pair<unsigned int, unsigned int> interval);
    void setAlgorithm(const char *algorithm);

private:
    std::pair<unsigned int, unsigned int> interval = {2, 1000};

    std::map<std::string, std::string> algorithms = {
        {"td", "trialDivision"},
        {"soe", "sieveOfEratosthenes"},
        {"sos", "sieveOfSundaram"},
        {"soa", "sieveOfAtkin"}
    };
    std::map<std::string, std::string> timeFormats = {
        {"ms", "milliseconds"},
        {"ns", "nanoseconds"},
        {"s", "seconds"},
    };
    std::map<std::string, std::string> modes = {
        {"p", "parallel"},
        {"s", "single"},
    };

    std::string timeFormat = "milliseconds";
    std::string algorithm = "trialDivision";
    std::string outputFile = "primes.txt";
    std::string mode = "single";
};

#endif // CONFIG_H