#pragma once

#include "../InputManager/CommandDecoder/CommandType.h"

class IOutputManager
{
public:

    virtual void PrintHelp() = 0;
};
