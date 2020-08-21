
#include "CommandBalance.h"

void CommandBalance::Execute(std::vector<std::string> arguments, IController *controller)
{
    ArgumentCountWarning(arguments.size());

    SyncManager->BalanceFiles();
}
