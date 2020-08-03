#pragma once

#include <string>
#include <set>

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

struct CommandArgument
{
    Command command;
    std::set<std::string> arguments;
};
