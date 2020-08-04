#pragma once

#include "../CommandDecoder/Command.h"

class IOutputManager
{
public:

    virtual void PrintCommand(Command& command) = 0;
};
