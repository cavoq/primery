#include <vector>
#include <bits/stdc++.h>
#include "../include/primegenerator.h"

PrimeGenerator::PrimeGenerator() {}

std::vector<unsigned int> PrimeGenerator::trailDivision(unsigned int start, unsigned int end)
{
    std::vector<unsigned int> primes;

    for (unsigned int n = start; n <= end; ++n)
    {
        bool isPrime = true;

        for (unsigned int j = 2; j < n; ++j)
        {
            if (n % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            primes.push_back(n);
        }
    }
    return primes;
}