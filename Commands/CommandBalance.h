#pragma once

#include "CommandBase.h"
#include "ISync.h"

class CommandBalance: public CommandBase
{
public:

    explicit CommandBalance(std::set<std::string> fullName, std::vector<std::string> arguments, std::string commandName,
                   Priority priority, ArgCount argc, ISync* Sync)
    : CommandBase(std::move(commandName), std::move(arguments), std::move(fullName), priority, argc)
    {
        SyncManager = Sync;
    }

    void Execute() override;

private:

    ISync* SyncManager;
};
