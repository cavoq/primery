#ifndef PRIMEGENERATOR_H
#define PRIMEGENERATOR_H

#include <vector>

class PrimeGenerator
{

public:
    virtual std::vector<unsigned int> &trialDivision(unsigned int start, unsigned int end) = 0;
    virtual std::vector<unsigned int> &sieveOfEratosthenes(unsigned int start, unsigned int end) = 0;
    virtual std::vector<unsigned int> &sieveOfSundaram(unsigned int start, unsigned int end) = 0;
    virtual std::vector<unsigned int> &sieveOfAtkin(unsigned int start, unsigned int end) = 0;

protected:
    inline static std::vector<unsigned int> primes;
};

#endif // PRIMEGENERATOR_H