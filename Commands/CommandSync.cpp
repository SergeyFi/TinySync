
#include "CommandSync.h"
#include "IGetSyncManager.h"

void CommandSync::Execute(std::vector<std::string> arguments, IController *controller)
{
    ArgumentCountWarning(arguments.size());

    auto GetSyncManager = dynamic_cast<IGetSyncManager*>(controller);

    if (GetSyncManager)
    {
        if (GetSyncManager->GetSyncManager())
        {
            GetSyncManager->GetSyncManager()->Sync();
        }
    }
}
