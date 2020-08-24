
#include "CommandHelp.h"

void CommandHelp::Execute()
{
    ArgumentCountWarning(commandArguments.size());

    OutputManager->PrintHelp();
}
