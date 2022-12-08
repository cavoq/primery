#include "../include/timer.h"

Timer::Timer() : startTime(std::chrono::high_resolution_clock::now()) {}

double Timer::getTime(double timeInNs, std::string &format)
{
    if (format == "nanoseconds")
        return timeInNs;
    if (format == "seconds")
        return timeInNs / 1000000000;
    return timeInNs / 1000000;
}