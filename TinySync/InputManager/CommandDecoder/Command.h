#pragma once

#include <string>
#include <vector>

enum class Command
{
    none,
    origin,
    target,
    filter,
    inverted,
    sync,
    clean,
    balance,
    help
};

struct Commands
{
    std::vector<Command> commands;
    std::vector<std::vector<std::string>> arguments;
};
