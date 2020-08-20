#pragma once

#include "CommandBase.h"
#include "../Controller/IGetOutputManager.h"

class CommandVersion: public CommandBase
{
public:

    CommandVersion(std::string newVersion, CommandType newName, std::set<std::string> commands) : CommandBase(newName, commands)
    {
        version = newVersion;
    }

    void Execute(std::vector<std::string> arguments, IController* controller) override;

private:

    std::string version;
};
