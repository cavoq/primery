#include <bits/stdc++.h>
#include "../include/primegenerator.h"

PrimeGenerator::PrimeGenerator() {}

std::vector<unsigned int> PrimeGenerator::trailDivision(unsigned int start, unsigned int end)
{
    std::vector<unsigned int> primes;

    for (unsigned int n = start; n <= end; ++n)
    {
        bool isPrime = true;
        unsigned int k = ceil(sqrt(n));

        for (unsigned int j = 2; j <= k; ++j)
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

std::vector<unsigned int> PrimeGenerator::sieveOfEratosthenes(unsigned int start, unsigned int end)
{
    std::vector<unsigned int> primes;

    bool prime[end + 1];
    memset(prime, true, sizeof(prime));

    for (unsigned int p = 2; p * p <= end; p++)
    {
        if (prime[p] == true)
        {
            for (unsigned int i = p * 2; i <= end; i += p)
                prime[i] = false;
        }
    }

    for (unsigned int p = start; p <= end; p++)
        if (prime[p])
        {
            primes.push_back(p);
        }

    return primes;
}