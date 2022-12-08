#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>
#include <vector>
#include "config.h"
#include "result.h"

class Timer
{

public:
    Timer();
    template <typename T, typename... Args>
    Result time(std::vector<unsigned int> &(T::*func)(Args...), T *obj, Config &config)
    {
        std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
        std::vector<unsigned int> primes = (obj->*func)(config.getInterval().first, config.getInterval().second);
        std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
        double time = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
        time = getTime(time, config.getTimeFormat());
        return Result(primes, time);
    }

private:
    double getTime(double time, std::string &format);

private:
    std::chrono::high_resolution_clock::time_point startTime;
};

#endif // TIMER_H