
#include "CommandCleanTarget.h"

void CommandCleanTarget::Execute()
{
    ArgumentCountWarning(commandArguments.size());

    SyncManager->CleanTarget();
}
