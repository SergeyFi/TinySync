
#include "CommandSync.h"

void CommandSync::Execute(std::vector<std::string> arguments)
{
    ArgumentCountWarning(arguments.size());

    SyncManager->Sync();
}
