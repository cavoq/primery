#include "../include/timer.h"

Timer::Timer() : startTime(std::chrono::high_resolution_clock::now()) {}

Result Timer::time(std::vector<unsigned int> &(*function)(unsigned int, unsigned int, std::string &mode), Config &config)
{
    std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
    std::vector<unsigned int> primes = (*function)(config.getInterval().first, config.getInterval().second, config.getMode());
    std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
    double time = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
    time = getTime(time, config.getTimeFormat());
    return Result(primes, time);
}

double Timer::getTime(double timeInNs, std::string &format)
{
    if (format == "nanoseconds")
        return timeInNs;
    if (format == "seconds")
        return timeInNs / 1000000000;
    return timeInNs / 1000000;
}