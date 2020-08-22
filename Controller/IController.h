#pragma once

#include "../CommandDecoder/CommandType.h"

class IController
{
public:

    virtual void InputCommand(std::vector<Command> commands) = 0;
};
