
#include "CommandBalance.h"

void CommandBalance::Execute(std::vector<std::string> arguments)
{
    ArgumentCountWarning(arguments.size());

    SyncManager->BalanceFiles();
}
