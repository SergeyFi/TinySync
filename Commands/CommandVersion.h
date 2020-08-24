#pragma once

#include "CommandBase.h"
#include "IOutputManager.h"

class CommandVersion: public CommandBase
{
public:

    CommandVersion(std::string commandName, std::string newVersion, int priority, int argc,
                   IOutputManager* OutManager)
    : CommandBase(std::move(commandName) ,priority, argc)
    {
        version = std::move(newVersion);
        OutputManager = OutManager;
    }

    void Execute() override;

private:

    std::string version;

    IOutputManager* OutputManager;
};
