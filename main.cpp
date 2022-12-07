#include <iostream>
#include <vector>

#include "include/primegenerator.h"
#include "include/timer.h"
#include "include/argumentparser.h"

void output(Result &result)
{
    std::cout << "number of primes: " << result.primes.size() << "\n";
    std::cout << "time: " << result.time << "\n";
}

void run(const char *algotithm, const char* timeFormat, std::pair<unsigned int, unsigned int> &interval, const char *outputFile)
{   
    PrimeGenerator primeGenerator = PrimeGenerator();
    Timer timer = Timer();
    Result result = Result();

    if (algotithm == "")
        return;
    if (algotithm == "trialDivision" || algotithm == "td")
        result = timer.time(primeGenerator.trailDivision, interval.first, interval.second, timeFormat);
    if (algotithm == "sieveOfEratosthenes" || algotithm == "soe")
        result = timer.time(primeGenerator.sieveOfEratosthenes, interval.first, interval.second, timeFormat);
    output(result);
}

int main(int argc, char *argv[])
{
    ArgumentParser argumentParser = ArgumentParser(argc, argv);
    argumentParser.parseArguments();
    
    const char *algotithm = argumentParser.getAlgorithm();
    const char *timeFormat = argumentParser.getTimeFormatArgument();
    std::pair<unsigned int, unsigned int> interval = argumentParser.getIntervalArgument();
    const char *outputFile = argumentParser.getOutputArgument();

    run(algotithm, timeFormat, interval, outputFile);
}