#include <iostream>
#include <vector>
#include "include/primegenerator.h"

void output(std::vector<unsigned int> &primes)
{
    for (int i = 0; i < primes.size(); ++i)
    {
        std::cout << i << " prime :" << primes[i] << "\n";
    }
}

int main(int argc, char *argv[])
{
    PrimeGenerator primeGenerator = PrimeGenerator();
    std::vector<unsigned int> primes = primeGenerator.sieveOfEratosthenes(2, 10000000);
    output(primes);
}