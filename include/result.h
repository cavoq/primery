#ifndef RESULT_H
#define RESULT_H

#include <iostream>
#include <vector>

class Result
{   

public:
    Result(std::vector<unsigned int> primes, double time);
    Result();
    void printResult();
    void writeToFile(std::string &fileName);
    
    void setResult(std::vector<unsigned int> &primes, double time);
    double getTime();
    std::vector<unsigned int> &getPrimes();


private:
    std::vector<unsigned int> primes;
    double time;
};

#endif // RESULT_H