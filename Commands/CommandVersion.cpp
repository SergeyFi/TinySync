
#include "CommandVersion.h"

void CommandVersion::Execute(std::vector<std::string> arguments, IController *controller)
{
    ArgumentCountWarning(arguments.size());

    OutputManager->PrintVesrion(version);
}
