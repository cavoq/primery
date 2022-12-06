#ifndef PRIMEGENERATOR_H
#define PRIMEGENERATOR_H

#include <vector>

class PrimeGenerator
{
    
public:
    PrimeGenerator();
    std::vector<unsigned int> trailDivision(unsigned int start, unsigned int end);
    std::vector<unsigned int> sieveOfEratosthenes(unsigned int start, unsigned int end);
};

#endif // PRIMEGENERATOR_H