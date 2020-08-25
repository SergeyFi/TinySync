#pragma once

#include "CommandBase.h"
#include "IOutputManager.h"

class CommandVersion: public CommandBase
{
public:

    explicit CommandVersion(CFullName fullName, CArg arguments, CName commandName,
                            std::string newVersion, Priority priority, ArgCount argc,IOutputManager* OutManager)
    : CommandBase(std::move(commandName), std::move(arguments), std::move(fullName) ,priority, argc)
    {
        version = std::move(newVersion);
        OutputManager = OutManager;
    }

    void Execute() override;

private:

    std::string version;

    IOutputManager* OutputManager;
};
