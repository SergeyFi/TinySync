
#include "CommandSync.h"

void CommandSync::Execute()
{
    const std::string syncUpdate = "-u";

    if(commandArguments.empty())
    {
        SyncManager->Sync();
    }
    else
    {
        if (commandArguments[0] == syncUpdate)
        {
            ArgumentCountWarning(commandArguments.size() - 1, commandName + " " + syncUpdate);
            SyncManager->SyncUpdate();
            return;
        }

        ArgumentCountWarning(commandArguments.size());
    }
}
