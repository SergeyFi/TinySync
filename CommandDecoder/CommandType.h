#pragma once

#include <string>
#include <vector>
#include <set>

using CommandFullName = std::set<std::string>;

struct Command
{
    std::set<std::string> commandFullName;
    std::vector<std::string> arguments;
};
