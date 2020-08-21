
#include "CommandSync.h"

void CommandSync::Execute(std::vector<std::string> arguments, IController *controller)
{
    ArgumentCountWarning(arguments.size());

    SyncManager->Sync();
}
