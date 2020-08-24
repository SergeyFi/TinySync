
#include "CommandSyncUpdate.h"

void CommandSyncUpdate::Execute()
{
    ArgumentCountWarning(commandArguments.size());

    SyncManager->SyncUpdate();
}
