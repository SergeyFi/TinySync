#pragma once

#include "CommandBase.h"
#include "IOutputManager.h"

class CommandHelp: public CommandBase
{
public:

    CommandHelp(std::string commandName, int priority, std::set<std::string> commands, int argc, IOutputManager* OutManager)
    : CommandBase(commandName ,priority, commands, argc)
    {
        OutputManager = OutManager;
    }

    void Execute(std::vector<std::string> arguments) override;

private:

    IOutputManager* OutputManager;
};
