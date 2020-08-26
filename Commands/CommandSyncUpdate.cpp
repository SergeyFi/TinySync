#include "CommandSyncUpdate.h"

void CommandSyncUpdate::Execute()
{
    SyncManager->SyncUpdate();
}
