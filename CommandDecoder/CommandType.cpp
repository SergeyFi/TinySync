#include "CommandType.h"

bool operator < (const CommandsList& a, const CommandsList& b)
{
    return a.commandsList < b.commandsList;
}

bool operator == (const CommandsList& a, const CommandsList& b)
{
    return a.commandsList == b.commandsList;
}