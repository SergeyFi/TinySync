
#include "CommandHelp.h"

void CommandHelp::Execute(std::vector<std::string> arguments, IController *controller)
{
    ArgumentCountWarning(arguments.size());

    OutputManager->PrintHelp();
}
