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

void run(std::string algorithm, std::string timeFormat, std::pair<unsigned int, unsigned int> interval, std::string outputFile)
{
    PrimeGenerator primeGenerator = PrimeGenerator();
    Timer timer = Timer();
    Result result = Result();

    if (algorithm == "")
        return;
    if (algorithm == "trialDivision" || algorithm == "td")
        result = timer.time(primeGenerator.trailDivision, interval.first, interval.second, timeFormat);
    if (algorithm == "sieveOfEratosthenes" || algorithm == "soe")
        result = timer.time(primeGenerator.sieveOfEratosthenes, interval.first, interval.second, timeFormat);

    output(result);
}

int main(int argc, char *argv[])
{
    ArgumentParser argumentParser = ArgumentParser(argc, argv);
    argumentParser.parseArguments();
    //argumentParser.debug();

    run(argumentParser.getAlgorithm(), argumentParser.getTimeFormatArgument(),
        argumentParser.getIntervalArgument(), argumentParser.getOutputArgument());
}