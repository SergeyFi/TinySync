
#include "CommandHelp.h"

void CommandHelp::Execute(std::vector<std::string> arguments)
{
    ArgumentCountWarning(arguments.size());

    OutputManager->PrintHelp();
}
