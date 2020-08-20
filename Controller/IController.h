#pragma once

#include "../InputManager/CommandDecoder/CommandType.h"

class IController
{
public:

    virtual void InputConsoleArgument(int argc, char* argv[]) = 0;

    virtual void InputCommand(std::vector<Command> commands) = 0;
};
