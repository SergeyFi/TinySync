#pragma once

#include "CommandBase.h"
#include "ISync.h"

class CommandSyncUpdate : public CommandBase
{
public:
    CommandSyncUpdate(std::string commandName, int priority, int argc, ISync* Sync)
    : CommandBase(std::move(commandName) ,priority, argc)
    {
        SyncManager = Sync;
    }

    void Execute() override;

private:

    ISync* SyncManager;
};