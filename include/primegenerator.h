#ifndef PRIMEGENERATOR_H
#define PRIMEGENERATOR_H

#include <vector>

class PrimeGenerator
{

public:
    PrimeGenerator();
    static std::vector<unsigned int> &trialDivision(unsigned int start, unsigned int end, std::string &mode);
    static std::vector<unsigned int> &sieveOfEratosthenes(unsigned int start, unsigned int end, std::string &mode);
    static std::vector<unsigned int> &sieveOfSundaram(unsigned int start, unsigned int end);

private:
    static std::vector<unsigned int> &sTrialDivision(unsigned int start, unsigned int end);
    static std::vector<unsigned int> &pTrialDivision(unsigned int start, unsigned int end);

    static std::vector<unsigned int> &sSieveOfEratosthenes(unsigned int start, unsigned int end);
    static std::vector<unsigned int> &pSieveOfEratosthenes(unsigned int start, unsigned int end);

private:
    inline static std::vector<unsigned int> primes;
};

#endif // PRIMEGENERATOR_H