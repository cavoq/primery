#ifndef MULTITHREADEDPRIMEGENERATOR_H
#define MULTITHREADEDPRIMEGENERATOR_H

#include "primegenerator.h"

class MultiThreadedPrimeGenerator : public PrimeGenerator
{

public:
    MultiThreadedPrimeGenerator();
    std::vector<unsigned int> &trialDivision(unsigned int start, unsigned int end) override;
    std::vector<unsigned int> &sieveOfEratosthenes(unsigned int start, unsigned int end) override;
};

#endif // MULTITHREADEDPRIMEGENERATOR_H