#ifndef ARGUMENTVALIDATOR_H
#define ARGUMENTVALIDATOR_H

#include <iostream>
#include <cstring>
#include "config.h"

class ArgumentValidator
{

public:
    ArgumentValidator();
    bool validateAlgorithm(const char *algorithm);
    bool validateTimeFormat(const char *timeFormat);
    bool validateInterval(std::string &interval);
    bool validateMode(const char *mode);
    bool validateOutputFile(const char *outputFile);

private:
    bool validate(const char **validArguments, const char *argument);

private:
    const char *validAlgorithms[9] = {"td", "trialDivision",
                                      "soe", "sieveOfEratosthenes",
                                      "sos", "sieveOfSundaram",
                                      "soa", "sieveOfAtkin", ""};
    const char *validTimeFormats[7] = {"ns", "nanoseconds",
                                       "ms", "milliseconds",
                                       "s", "seconds", ""};
    const char *validModes[5] = {"s", "single",
                                 "p", "parallel", ""};
};

#endif // ARGUMENTVALIDATOR_H