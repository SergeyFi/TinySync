#pragma once

#include "ICommand.h"

class CommandBase : public ICommand
{

public:

    CommandBase(CommandType newName,int priority, std::set<std::string> commands)
    {
        name = newName;
        commandPriority = priority;
        rawCommands = commands;
    }

    CommandType GetName() const override;

    std::set<std::string> GetRawCommands() const override;

    int GetCommandPriority() const override;

protected:

    CommandType name;

    std::set<std::string> rawCommands;

    int commandPriority;
};
