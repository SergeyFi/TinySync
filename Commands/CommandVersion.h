#pragma once

#include "CommandBase.h"
#include "../Controller/IGetOutputManager.h"

class CommandVersion: public CommandBase
{
public:

    CommandVersion(std::string newVersion, CommandType newName, int priority, std::set<std::string> commands, int argc)
    : CommandBase(newName, priority, commands, argc)
    {
        version = newVersion;
    }

    void Execute(std::vector<std::string> arguments, IController* controller) override;

private:

    std::string version;
};
