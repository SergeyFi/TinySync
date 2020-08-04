#pragma once

#include "../InputManager/CommandDecoder/Command.h"

class IOutputManager
{
public:

    virtual void PrintCommand(Commands& command) = 0;
};
