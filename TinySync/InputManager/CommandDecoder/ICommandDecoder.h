#pragma once

#include "Command.h"

class ICommandDecoder
{
public:

    virtual void AddRawData(int argc, char* argv[]) = 0;
};
