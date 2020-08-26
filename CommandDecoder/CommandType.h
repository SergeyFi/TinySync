#pragma once

#include <string>
#include <vector>
#include <set>

struct Command
{
    std::set<std::string> commandFullName;
    std::vector<std::string> arguments;
};
