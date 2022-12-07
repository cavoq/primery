#include "../include/timer.h"

Timer::Timer() : startTime(std::chrono::steady_clock::now()) {}

Result Timer::time(std::vector<unsigned int> (*function)(unsigned int, unsigned int), unsigned int start, unsigned int end, const char *format)
{
    std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
    std::vector<unsigned int> primes = (*function)(start, end);
    std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
    double time = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
    time = getTime(time, format);
    return Result(primes, time);
}

double Timer::getTime(double timeInNs, const char *format)
{
    if (format == "ns")
        return timeInNs;
    if (format == "s")
        return timeInNs / 1000000000;
    return timeInNs / 1000000;
}