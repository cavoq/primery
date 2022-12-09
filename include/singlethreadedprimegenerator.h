#ifndef SINGLETHREADEDPRIMEGENERATOR_H
#define SINGLETHREADEDPRIMEGENERATOR_H

#include "primegenerator.h"

class SingleThreadedPrimeGenerator : public PrimeGenerator
{

public:
    SingleThreadedPrimeGenerator();
    std::vector<unsigned int> &trialDivision(unsigned int start, unsigned int end) override;
    std::vector<unsigned int> &sieveOfEratosthenes(unsigned int start, unsigned int end) override;
    std::vector<unsigned int> &sieveOfSundaram(unsigned int start, unsigned int end) override;
    std::vector<unsigned int> &sieveOfAtkin(unsigned int start, unsigned int end) override;

};

#endif // SINGLETHREADEDPRIMEGENERATOR_H