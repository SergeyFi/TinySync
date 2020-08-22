#pragma once

#include "../CommandDecoder/CommandType.h"

class ICommandExecutor
{
public:

    virtual void InputCommand(std::vector<Command> commands) = 0;
};
