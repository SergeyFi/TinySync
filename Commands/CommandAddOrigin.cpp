#include "CommandAddOrigin.h"


void CommandAddOrigin::Execute()
{
    ArgumentCountWarning(commandArguments.size());

    SyncManager->AddOrigin(commandArguments[0]);
}
