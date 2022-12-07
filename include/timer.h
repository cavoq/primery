#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <vector>
#include <iostream>
#include "config.h"
#include "result.h"

class Timer
{

public:
    Timer();
    Result time(std::vector<unsigned int> (*function)(unsigned int, unsigned int), Config &config);

private:
    double getTime(double time, std::string &format);

private:
    std::chrono::steady_clock::time_point startTime;
};

#endif // TIMER_H