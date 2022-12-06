#include <iostream>
#include <vector>
#include "include/primegenerator.h"
#include "include/timer.h"

void output(Result &result)
{
    std::cout << "number of primes: " << result.primes.size() << "\n";
    std::cout << "time: " << result.time << "\n";
}

int main(int argc, char *argv[])
{
    Timer timer = Timer();
    PrimeGenerator primeGenerator = PrimeGenerator();
    Result result = timer.time([&primeGenerator](){ primeGenerator.sieveOfEratosthenes(2, 1000); });
    output(result);
}