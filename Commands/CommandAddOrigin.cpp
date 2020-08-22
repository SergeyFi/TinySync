#include "CommandAddOrigin.h"


void CommandAddOrigin::Execute(std::vector<std::string> arguments)
{
    ArgumentCountWarning(arguments.size());

    SyncManager->AddOrigin(arguments[0]);
}
