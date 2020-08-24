
#include "CommandSync.h"

void CommandSync::Execute()
{
    ArgumentCountWarning(commandArguments.size());

    SyncManager->Sync();
}
