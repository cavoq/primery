#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <vector>

struct Result
{
    std::vector<unsigned int> primes;
    double time;

    Result(std::vector<unsigned int> primes, double time) : primes(primes), time(time) {}
};

class Timer
{

public:
    Timer();
    Result time(std::vector<unsigned int> (*function)(unsigned int, unsigned int), unsigned int start, unsigned int end);

private:
    double getTime(double time, const char *format);
    
private:
    std::chrono::steady_clock::time_point startTime;
};

#endif // TIMER_H