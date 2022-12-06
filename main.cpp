#include <iostream>
#include <vector>
#include "include/primegenerator.h"
#include "include/timer.h"

void output(Result &result)
{
    for (int i = 0; i < result.primes.size(); ++i)
    {
        std::cout << i << " prime :" << result.primes[i] << "\n";
    }
    std::cout << "time: " << result.time << "\n";
}

int main(int argc, char *argv[])
{
    Timer timer;
    PrimeGenerator primeGenerator = PrimeGenerator();
    Result result = timer.time([](){ sieveOfEratosthenes(2, 10); });
    output(result);
}