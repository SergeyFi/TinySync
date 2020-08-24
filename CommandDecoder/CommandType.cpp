#include "CommandType.h"

bool operator < (const CommandFullName& a, const CommandFullName& b)
{
    return a.fullName < b.fullName;
}

bool operator == (const CommandFullName& a, const CommandFullName& b)
{
    return a.fullName == b.fullName;
}