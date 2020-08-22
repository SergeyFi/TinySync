
#include "CommandCleanTarget.h"

void CommandCleanTarget::Execute(std::vector<std::string> arguments)
{
    ArgumentCountWarning(arguments.size());

    SyncManager->CleanTarget();
}
