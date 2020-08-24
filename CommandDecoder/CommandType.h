#pragma once

#include <string>
#include <vector>
#include <set>

struct CommandFullName
{
    std::set<std::string> fullName;
};

bool operator < (const CommandFullName& a, const CommandFullName& b);

bool operator == (const CommandFullName& a, const CommandFullName& b);

struct Command
{
    std::set<std::string> commandFullName;
    std::vector<std::string> arguments;
};
