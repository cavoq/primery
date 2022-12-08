#include <iostream>
#include <vector>

#include "include/primegenerator.h"
#include "include/singlethreadedprimegenerator.h"
#include "include/multithreadedprimegenerator.h"

#include "include/timer.h"
#include "include/argumentparser.h"

PrimeGenerator *setupPrimeGenerator(Config &config)
{
    if (config.getMode() == "parallel")
        return new MultiThreadedPrimeGenerator();
    return new SingleThreadedPrimeGenerator();
}

void output(Result &result, Config &config)
{
    config.printConfig();
    result.printResult();
}

void run(Config &config)
{
    PrimeGenerator *primeGenerator = setupPrimeGenerator(config);

    Timer timer = Timer();
    Result result = Result();
    std::string algorithm = config.getAlgorithm();

    if (algorithm == "trialDivision")
        result = timer.time(&PrimeGenerator::trialDivision, primeGenerator, config);
    if (algorithm == "sieveOfEratosthenes")
        result = timer.time(&PrimeGenerator::sieveOfEratosthenes, primeGenerator, config);

    delete primeGenerator;

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