#pragma once

#include "CommandBase.h"
#include "ISync.h"

class CommandBalance: public CommandBase
{
public:

    explicit CommandBalance(CFullName fullName, CArg arguments, CName commandName, Priority priority, ArgCount argc, ISync* Sync)
    : CommandBase(std::move(commandName), std::move(arguments), std::move(fullName), priority, argc)
    {
        SyncManager = Sync;
    }

    void Execute() override;

private:

    ISync* SyncManager;
};
