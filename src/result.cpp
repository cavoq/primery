#include "../include/result.h"
#include <cstring>

Result::Result() {}

void Result::printResult()
{

    std::cout << "RESULT: "
              << "\n";
    std::cout << "  Time   : " << time << "\n";
    std::cout << "  Primes : " << primes.size() << "\n";
}

Result::Result(std::vector<unsigned int> primes, double time) : primes(primes), time(time) {}

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
