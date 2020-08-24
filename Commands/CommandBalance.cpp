
#include "CommandBalance.h"

void CommandBalance::Execute()
{
    ArgumentCountWarning(commandArguments.size());

    SyncManager->BalanceFiles();
}
