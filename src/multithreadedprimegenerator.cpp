#include <bits/stdc++.h>
#include <execution>
#include <algorithm>

#include "../include/utils.h"
#include "../include/multithreadedprimegenerator.h"

MultiThreadedPrimeGenerator::MultiThreadedPrimeGenerator() {}

std::vector<unsigned int> &MultiThreadedPrimeGenerator::trialDivision(unsigned int start, unsigned int end)
{
    primes.clear();

    if (start == 2)
        primes.push_back(2);

    std::vector<unsigned int> numbers = utils::generateArray(start, end);

    std::for_each(std::execution::par, numbers.begin(), numbers.end(),
                  [&](unsigned int n)
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
                  });

    return primes;
}

std::vector<unsigned int> &MultiThreadedPrimeGenerator::sieveOfEratosthenes(unsigned int start, unsigned int end)
{
    primes.clear();

    bool *prime = new bool[end + 1];
    memset(prime, 1, sizeof(bool) * (end + 1));

    std::vector<std::future<void>> futures;

    for (unsigned int p = 2; p * p <= end; p++)
    {
        if (prime[p] == true)
        {
            futures.push_back(std::async(std::launch::async,
                                         [p, prime, end]
                                         {
                                             for (unsigned int i = p * 2; i <= end; i += p)
                                                 prime[i] = false;
                                         }));
        }
    }

    for (auto &f : futures)
        f.wait();

    for (unsigned int p = start; p <= end; p++)
        if (prime[p])
        {
            primes.push_back(p);
        }

    delete[] prime;

    return primes;
}

std::vector<unsigned int> &MultiThreadedPrimeGenerator::sieveOfSundaram(unsigned int start, unsigned int end)
{
    primes.clear();

    unsigned int max = (end - start) / 2;

    std::atomic<bool> *eliminated = new std::atomic<bool>[max + 1];
    memset(eliminated, 0, sizeof(std::atomic<bool>) * (max + 1));

    std::vector<std::future<void>> futures;

    for (unsigned int i = 1; i <= max; ++i)
    {
        futures.push_back(std::async(std::launch::deferred,
                                     [i, max, eliminated]()
                                     {
                                         for (unsigned int j = i; (i + j + 2 * i * j) <= max; ++j)
                                         {
                                             eliminated[i + j + 2 * i * j].store(true, std::memory_order_relaxed);
                                         }
                                     }));
    }

    for (auto &future : futures)
    {
        future.wait();
    }

    for (unsigned int i = 1; i <= max; ++i)
    {
        if (!eliminated[i].load(std::memory_order_relaxed))
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
