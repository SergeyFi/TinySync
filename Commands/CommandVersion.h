#pragma once

#include "CommandBase.h"
#include "../Controller/IGetOutputManager.h"

class CommandVersion: public CommandBase
{
public:

    CommandVersion(std::string commandName, std::string newVersion, int priority, std::set<std::string> commands, int argc)
    : CommandBase(commandName ,priority, commands, argc)
    {
        version = newVersion;
    }

    void Execute(std::vector<std::string> arguments, IController* controller) override;

private:

    std::string version;
};
