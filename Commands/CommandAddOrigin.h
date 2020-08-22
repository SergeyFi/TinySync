#pragma once

#include "CommandBase.h"
#include "ISync.h"

class CommandAddOrigin: public CommandBase
{
public:

    CommandAddOrigin(std::string commandName, int priority, std::set<std::string> commands, int argc, ISync* Sync)
    : CommandBase(commandName ,priority, commands, argc)
    {
        SyncManager = Sync;
    }

    void Execute(std::vector<std::string> arguments) override;

private:

    ISync* SyncManager;
};
