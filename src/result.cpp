#include "../include/result.h"
#include <fstream>

Result::Result() {}

void Result::printResult()
{

    std::cout << "RESULT: "
              << "\n";
    std::cout << "  Time   : " << time << "\n";
    std::cout << "  Primes : " << primes.size() << "\n";
}

Result::Result(std::vector<unsigned int> primes, double time) : primes(primes), time(time) {}

void Result::adjust()
{
    for (unsigned int i = 0; i < primes.size(); ++i)
    {
        if (primes[i] >= 2)
            return;
        primes.erase(primes.begin() + i);
    }
}

void Result::writeToFile(std::string &fileName)
{
    std::ofstream outputFile(fileName);
    for (int i = 0; i < primes.size(); ++i)
    {
        outputFile << primes[i] << "\n";
    }
    outputFile.close();
}

void Result::setResult(std::vector<unsigned int> &primes, double time)
{
    this->primes = primes;
    this->time = time;
}

std::vector<unsigned int> &Result::getPrimes()
{
    return primes;
}

double Result::getTime()
{
    return time;
}
