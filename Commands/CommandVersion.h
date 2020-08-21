#pragma once

#include "CommandBase.h"
#include "IOutputManager.h"

class CommandVersion: public CommandBase
{
public:

    CommandVersion(std::string commandName, std::string newVersion, int priority, std::set<std::string> commands, int argc,
                   IOutputManager* OutManager)
    : CommandBase(commandName ,priority, commands, argc)
    {
        version = newVersion;
        OutputManager = OutManager;
    }

    void Execute(std::vector<std::string> arguments, IController* controller) override;

private:

    std::string version;

    IOutputManager* OutputManager;
};
