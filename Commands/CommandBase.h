#pragma once

#include "ICommand.h"

#include "../Logger/GetLogger.h"

class CommandBase : public ICommand
{

public:

    CommandBase(std::string newCommandName, int priority, std::set<std::string> commands, int argc)
    {
        commandPriority = priority;
        commandsList.commandsList = commands;
        commandArgumentCount = argc;
        commandName = newCommandName;
    }

    CommandsList GetCommandsList() const override;

    int GetCommandPriority() const override;

protected:

    std::string commandName;

    CommandsList commandsList;

    int commandPriority;

    int commandArgumentCount;

    void ArgumentCountWarning(int argumentsGiven);
};
