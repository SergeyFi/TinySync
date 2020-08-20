#pragma once

#include "ICommand.h"

class CommandBase : public ICommand
{

public:

    CommandBase(CommandType newName, std::set<std::string> commands)
    {
        name = newName;
        rawCommands = commands;
    }

    CommandType GetName() const override;

    std::set<std::string> GetRawCommands() const override;

protected:

    CommandType name;

    std::set<std::string> rawCommands;
};
