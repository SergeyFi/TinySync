
#include "CommandVersion.h"

void CommandVersion::Execute(std::vector<std::string> arguments, IController *controller)
{
    ArgumentCountWarning(arguments.size());

    auto GetSyncManager = dynamic_cast<IGetOutputManager*>(controller);

    if (GetSyncManager)
    {
        if (GetSyncManager->GetOutputManager())
        {
            GetSyncManager->GetOutputManager()->PrintVesrion(version);
        }
    }
}
