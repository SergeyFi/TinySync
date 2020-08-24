#pragma once

#include "CommandBase.h"
#include "IOutputManager.h"

class CommandHelp: public CommandBase
{
public:

    CommandHelp(std::string commandName, int priority, int argc, IOutputManager* OutManager)
    : CommandBase(std::move(commandName) ,priority, argc)
    {
        OutputManager = OutManager;
    }

    void Execute() override;

private:

    IOutputManager* OutputManager;
};
