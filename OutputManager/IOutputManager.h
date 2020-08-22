#pragma once

#include "../CommandDecoder/CommandType.h"

class IOutputManager
{
public:

    virtual void PrintHelp() = 0;

    virtual void PrintVesrion(std::string version) const = 0;
};
