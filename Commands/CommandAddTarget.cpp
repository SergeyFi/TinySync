
#include "CommandAddTarget.h"
#include "IGetSyncManager.h"

void CommandAddTarget::Execute(std::vector<std::string> arguments, IController *controller)
{
    auto GetSyncManager = dynamic_cast<IGetSyncManager*>(controller);

    if (GetSyncManager)
    {
        if (GetSyncManager->GetSyncManager())
        {
            GetSyncManager->GetSyncManager()->AddTarget(arguments[0]);
        }
    }
}

CommandType CommandAddTarget::GetName()
{
    return name;
}
