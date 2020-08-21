#pragma once

#include <string>
#include <vector>
#include <set>

struct CommandsList
{
    std::set<std::string> commandsList;
};

bool operator < (const CommandsList& a, const CommandsList& b);

bool operator == (const CommandsList& a, const CommandsList& b);

struct Command
{
    std::string commandName;
    std::vector<std::string> arguments;
};
