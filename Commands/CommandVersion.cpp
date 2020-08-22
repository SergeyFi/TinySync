
#include "CommandVersion.h"

void CommandVersion::Execute(std::vector<std::string> arguments)
{
    ArgumentCountWarning(arguments.size());

    OutputManager->PrintVersion(version);
}
