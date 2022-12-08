#include <iostream>
#include <vector>

#include "include/primegenerator.h"
#include "include/timer.h"
#include "include/argumentparser.h"

void output(Result &result, Config &config)
{
    config.printConfig();
    result.printResult();
}

void run(Config &config)
{
    PrimeGenerator primeGenerator = PrimeGenerator();
    Timer timer = Timer();
    Result result = Result();
    std::string algorithm = config.getAlgorithm();

    if (algorithm == "trialDivision")
        result = timer.time(primeGenerator.trialDivision, config);
    if (algorithm == "sieveOfEratosthenes")
        result = timer.time(primeGenerator.sieveOfEratosthenes, config);

    result.adjust();
    result.writeToFile(config.getOutputFile());
    output(result, config);
}

int main(int argc, char *argv[])
{
    Config config = Config();
    ArgumentParser argumentParser = ArgumentParser();
    if (!argumentParser.parse(argc, argv, config))
        return 0;
    run(config);
}