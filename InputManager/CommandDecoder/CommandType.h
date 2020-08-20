﻿#pragma once

#include <string>
#include <vector>

enum class CommandType
{
    none,
    origin,
    target,
    filter,
    inverted_filter,
    sync,
    clean,
    balance,
    help
};

struct Command
{
    CommandType command;
    std::vector<std::string> arguments;
};