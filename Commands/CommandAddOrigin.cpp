#include "CommandAddOrigin.h"
#include "IGetSyncManager.h"

void CommandAddOrigin::Execute(std::vector<std::string> arguments, IController* controller)
{
    auto GetSyncManager = dynamic_cast<IGetSyncManager*>(controller);

    if (GetSyncManager)
    {
        if (GetSyncManager->GetSyncManager())
        {
            GetSyncManager->GetSyncManager()->AddOrigin(arguments[0]);
        }
    }
}

CommandType CommandAddOrigin::GetName()
{
    return name;
}
