#pragma once

#include "ICommand.h"

#include "../Logger/GetLogger.h"

class CommandBase : public ICommand
{

public:

    CommandBase(int priority, std::set<std::string> commands, int argc)
    {
        commandPriority = priority;
        commandsList.commandsList = commands;
        commandArgumentCount = argc;
    }

    CommandsList GetCommandsList() const override;

    int GetCommandPriority() const override;

protected:

    CommandsList commandsList;

    int commandPriority;

    int commandArgumentCount;

    void ArgumentCountWarning(int argumentsGiven);
};
