#include <vector>
#include <map>
#include <string>

#ifndef UTILS_H
#define UTILS_H

namespace utils
{
    std::vector<unsigned int> generateArray(unsigned int start, unsigned int end);
    std::string mapString(const std::string &input, const std::map<std::string, std::string> &map);
    std::vector<std::string> split(const std::string &str, char delim);
}

#endif // UTILS_H