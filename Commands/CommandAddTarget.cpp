
#include "CommandAddTarget.h"


void CommandAddTarget::Execute()
{
    ArgumentCountWarning(commandArguments.size());

    SyncManager->AddTarget(commandArguments[0]);
}
