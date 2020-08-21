#pragma once

#include "CommandBase.h"
#include "ISync.h"

class CommandBalance: public CommandBase
{
public:

    CommandBalance(std::string commandName, int priority, std::set<std::string> commands, int argc, ISync* Sync)
    : CommandBase(commandName ,priority, commands, argc)
    {
        SyncManager = Sync;
    }

    void Execute(std::vector<std::string> arguments, IController* controller) override;

private:

    ISync* SyncManager;
};
