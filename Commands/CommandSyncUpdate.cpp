
#include "CommandSyncUpdate.h"

void CommandSyncUpdate::Execute(std::vector<std::string> arguments, IController *controller)
{
    ArgumentCountWarning(arguments.size());

    SyncManager->SyncUpdate();
}
