
#include "CommandAddTarget.h"


void CommandAddTarget::Execute(std::vector<std::string> arguments)
{
    ArgumentCountWarning(arguments.size());

    SyncManager->AddTarget(arguments[0]);
}
