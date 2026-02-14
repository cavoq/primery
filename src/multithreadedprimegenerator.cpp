#include <algorithm>
#include <atomic>
#include <cmath>
#include <execution>
#include <thread>
#include <vector>

#include "../include/utils.h"
#include "../include/multithreadedprimegenerator.h"

MultiThreadedPrimeGenerator::MultiThreadedPrimeGenerator() {}

std::vector<unsigned int> &MultiThreadedPrimeGenerator::trialDivision(unsigned int start, unsigned int end)
{
    primes.clear();

    if (start > end)
        return primes;

    const unsigned int begin = std::max(start, 2u);
    if (begin > end)
        return primes;

    std::vector<unsigned int> numbers = utils::generateArray(begin, end);
    std::vector<unsigned char> isPrime(numbers.size(), 0);

    std::for_each(std::execution::par, numbers.begin(), numbers.end(),
                  [&](unsigned int n)
                  {
                      bool prime = true;
                      unsigned int k = ceil(sqrt(n));

                      for (unsigned int j = 2; j <= k; ++j)
                      {
                          if (n % j == 0)
                          {
                              prime = false;
                              break;
                          }
                      }

                      isPrime[n - begin] = prime ? 1 : 0;
                  });

    primes.reserve(numbers.size());
    for (size_t i = 0; i < numbers.size(); ++i)
        if (isPrime[i])
            primes.push_back(numbers[i]);

    return primes;
}

std::vector<unsigned int> &MultiThreadedPrimeGenerator::sieveOfEratosthenes(unsigned int start, unsigned int end)
{
    primes.clear();

    if (start > end)
        return primes;

    std::vector<std::atomic_bool> prime(end + 1);
    for (unsigned int i = 0; i <= end; ++i)
        prime[i].store(true, std::memory_order_relaxed);
    prime[0].store(false, std::memory_order_relaxed);
    if (end >= 1)
        prime[1].store(false, std::memory_order_relaxed);

    const unsigned int limit = static_cast<unsigned int>(std::sqrt(end));
    std::vector<bool> base(limit + 1, true);
    base[0] = false;
    if (limit >= 1)
        base[1] = false;

    for (unsigned int p = 2; p * p <= limit; ++p)
    {
        if (!base[p])
            continue;
        for (unsigned int i = p * p; i <= limit; i += p)
            base[i] = false;
    }

    std::vector<unsigned int> basePrimes;
    for (unsigned int p = 2; p <= limit; ++p)
        if (base[p])
            basePrimes.push_back(p);

    unsigned int threadCount = std::thread::hardware_concurrency();
    if (threadCount == 0)
        threadCount = 2;
    if (threadCount > basePrimes.size())
        threadCount = static_cast<unsigned int>(basePrimes.size());
    if (threadCount == 0)
        threadCount = 1;

    std::vector<std::thread> workers;
    workers.reserve(threadCount);

    for (unsigned int t = 0; t < threadCount; ++t)
    {
        workers.emplace_back([t, threadCount, end, &basePrimes, &prime]()
                             {
                                 for (size_t idx = t; idx < basePrimes.size(); idx += threadCount)
                                 {
                                     const unsigned int p = basePrimes[idx];
                                     for (unsigned int i = p * p; i <= end; i += p)
                                         prime[i].store(false, std::memory_order_relaxed);
                                 } });
    }

    for (std::thread &worker : workers)
        worker.join();

    const unsigned int begin = std::max(start, 2u);
    for (unsigned int p = begin; p <= end; ++p)
        if (prime[p].load(std::memory_order_relaxed))
        {
            primes.push_back(p);
        }

    return primes;
}

std::vector<unsigned int> &MultiThreadedPrimeGenerator::sieveOfSundaram(unsigned int start, unsigned int end)
{
    primes.clear();

    if (start > end)
        return primes;

    unsigned int max = (end - start) / 2;

    std::vector<std::atomic_bool> eliminated(max + 1);
    for (unsigned int i = 0; i <= max; ++i)
        eliminated[i].store(false, std::memory_order_relaxed);

    std::vector<unsigned int> values = utils::generateArray(1, max);
    std::for_each(std::execution::par, values.begin(), values.end(),
                  [&](unsigned int i)
                  {
                      for (unsigned int j = i; (i + j + 2 * i * j) <= max; ++j)
                          eliminated[i + j + 2 * i * j].store(true, std::memory_order_relaxed);
                  });

    if (start == 2)
        primes.push_back(2);

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

    return primes;
}

std::vector<unsigned int> &MultiThreadedPrimeGenerator::sieveOfAtkin(unsigned int start, unsigned int end)
{
    primes.clear();

    if (start > end)
        return primes;

    std::vector<std::atomic<unsigned char>> sieve(end + 1);
    for (unsigned int i = 0; i <= end; ++i)
        sieve[i].store(0, std::memory_order_relaxed);

    const unsigned int limit = static_cast<unsigned int>(std::sqrt(end));
    std::vector<unsigned int> xValues = utils::generateArray(1, limit);

    std::for_each(std::execution::par, xValues.begin(), xValues.end(),
                  [&](unsigned int x)
                  {
                      for (unsigned int y = 1; y * y <= end; ++y)
                      {
                          unsigned int n = (4 * x * x) + (y * y);
                          if (n <= end && (n % 12 == 1 || n % 12 == 5))
                              sieve[n].fetch_xor(1, std::memory_order_relaxed);

                          n = (3 * x * x) + (y * y);
                          if (n <= end && n % 12 == 7)
                              sieve[n].fetch_xor(1, std::memory_order_relaxed);

                          if (x > y)
                          {
                              n = (3 * x * x) - (y * y);
                              if (n <= end && n % 12 == 11)
                                  sieve[n].fetch_xor(1, std::memory_order_relaxed);
                          }
                      }
                  });

    for (unsigned int r = 5; r * r <= end; r++)
    {
        if (sieve[r].load(std::memory_order_relaxed))
        {
            for (unsigned int i = r * r; i <= end; i += r * r)
                sieve[i].store(0, std::memory_order_relaxed);
        }
    }

    for (unsigned int i = start; i <= end; ++i)
    {
        if (sieve[i].load(std::memory_order_relaxed))
            primes.push_back(i);
    }

    return primes;
}
