#include "../include/timer.h"
#include <vector>

Timer::Timer() : startTime(std::chrono::steady_clock::now()) {}

template <typename Function>
Result Timer::time(Function f)
{
    std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
    std::vector<unsigned int> primes = f();
    std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
    double time = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    return Result(primes, time);
}