#pragma once

#include "../CommandDecoder/Command.h"

class IController
{
public:

    virtual void InputConsoleArgument(int argc, char* argv[]) = 0;

    virtual void InputCommand(Command command) = 0;
};
