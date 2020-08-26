
#include "CommandSync.h"

void CommandSync::Execute()
{
    if(commandArguments.empty())
    {
        SyncManager->Sync();
    }
}
