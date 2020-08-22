#pragma once

#include "CommandType.h"

class ICommandDecoder
{
public:

    virtual void AddRawData(int argc, char* argv[]) = 0;
};
