
#include "CommandCleanTarget.h"

void CommandCleanTarget::Execute(std::vector<std::string> arguments, IController *controller)
{
    ArgumentCountWarning(arguments.size());

    SyncManager->CleanTarget();
}
