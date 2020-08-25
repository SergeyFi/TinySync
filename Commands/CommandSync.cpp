
#include "CommandSync.h"

void CommandSync::Execute()
{
    if (commandArguments[0] == "-u")
    {
        SyncManager->SyncUpdate();
    }

    else
    {
        ArgumentCountWarning(commandArguments.size());

        SyncManager->Sync();
    }
}
