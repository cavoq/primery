#include <bits/stdc++.h>
#include <algorithm>

#include "../include/utils.h"
#include "../include/singlethreadedprimegenerator.h"

SingleThreadedPrimeGenerator::SingleThreadedPrimeGenerator() {}

std::vector<unsigned int> &SingleThreadedPrimeGenerator::trialDivision(unsigned int start, unsigned int end)
{
    primes.clear();

    if (start == 2)
        primes.push_back(2);

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

std::vector<unsigned int> &SingleThreadedPrimeGenerator::sieveOfEratosthenes(unsigned int start, unsigned int end)
{
    primes.clear();

    bool *prime = new bool[end + 1];
    memset(prime, 1, sizeof(bool) * (end + 1));

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

    delete[] prime;

    return primes;
}

std::vector<unsigned int> &SingleThreadedPrimeGenerator::sieveOfSundaram(unsigned int start, unsigned int end)
{
    primes.clear();

    unsigned int max = (end - start) / 2;

    bool *eliminated = new bool[max + 1];
    memset(eliminated, 0, sizeof(bool) * (max + 1));

    for (unsigned int i = 1; i <= max; ++i)
    {
        for (unsigned int j = i; (i + j + 2 * i * j) <= max; ++j)
        {
            eliminated[i + j + 2 * i * j] = true;
        }
    }

    if (start == 2)
        primes.push_back(2);

    for (unsigned int i = 1; i <= max; ++i)
    {
        if (!eliminated[i])
        {
            unsigned int prime = 2 * i + 1;
            if (prime >= start && prime <= end)
            {
                primes.push_back(prime);
            }
        }
    }

    delete[] eliminated;

    return primes;
}

std::vector<unsigned int> &SingleThreadedPrimeGenerator::sieveOfAtkin(unsigned int start, unsigned int end)
{
    primes.clear();

    bool *sieve = new bool[end + 1];
    memset(sieve, 0, sizeof(bool) * (end + 1));

    for (int x = 1; x * x <= end; x++)
    {
        for (int y = 1; y * y <= end; y++)
        {

            int n = (4 * x * x) + (y * y);
            if (n <= end && (n % 12 == 1 || n % 12 == 5))
                sieve[n] = !sieve[n];

            n = (3 * x * x) + (y * y);
            if (n <= end && n % 12 == 7)
                sieve[n] = !sieve[n];

            n = (3 * x * x) - (y * y);
            if (x > y && n <= end && n % 12 == 11)
                sieve[n] = !sieve[n];
        }
    }

    for (int r = 5; r * r <= end; r++)
    {
        if (sieve[r])
        {
            for (int i = r * r; i <= end; i += r * r)
                sieve[i] = false;
        }
    }

    for (unsigned int i = start; i <= end; ++i)
    {
        if (sieve[i])
            primes.push_back(i);
    }

    delete[] sieve;

    return primes;
}