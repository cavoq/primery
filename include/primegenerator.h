#ifndef PRIMEGENERATOR_H
#define PRIMEGENERATOR_H

#include <vector>

class PrimeGenerator
{

public:
    PrimeGenerator();
    static std::vector<unsigned int> trailDivision(unsigned int start, unsigned int end);
    static std::vector<unsigned int> sieveOfEratosthenes(unsigned int start, unsigned int end);
};

#endif // PRIMEGENERATOR_H