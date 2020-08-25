#pragma once

#include "CommandBase.h"
#include "IOutputManager.h"

class CommandHelp: public CommandBase
{
public:

    explicit CommandHelp(std::set<std::string> fullName, std::vector<std::string> arguments, std::string commandName,
                Priority priority, ArgCount argc, IOutputManager* OutManager)
    : CommandBase(std::move(commandName), std::move(arguments), std::move(fullName) ,priority, argc)
    {
        OutputManager = OutManager;
    }

    void Execute() override;

private:

    IOutputManager* OutputManager;
};
