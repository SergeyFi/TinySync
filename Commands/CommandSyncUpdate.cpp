
#include "CommandSyncUpdate.h"
#include "IGetSyncManager.h"

void CommandSyncUpdate::Execute(std::vector<std::string> arguments, IController *controller)
{
    ArgumentCountWarning(arguments.size());

    auto GetSyncManager = dynamic_cast<IGetSyncManager*>(controller);

    if (GetSyncManager)
    {
        if (GetSyncManager->GetSyncManager())
        {
            GetSyncManager->GetSyncManager()->SyncUpdate();
        }
    }
}
