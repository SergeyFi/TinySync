
#include "CommandSyncUpdate.h"

void CommandSyncUpdate::Execute(std::vector<std::string> arguments)
{
    ArgumentCountWarning(arguments.size());

    SyncManager->SyncUpdate();
}
