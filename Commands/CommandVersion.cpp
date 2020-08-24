
#include "CommandVersion.h"

void CommandVersion::Execute()
{
    ArgumentCountWarning(commandArguments.size());

    OutputManager->PrintVersion(version);
}
