//
// Created by Oni on 8/20/2020.
//

#include "CommandHelp.h"

void CommandHelp::Execute(std::vector<std::string> arguments, IController *controller)
{
    auto GetSyncManager = dynamic_cast<IGetOutputManager*>(controller);

    if (GetSyncManager)
    {
        if (GetSyncManager->GetOutputManager())
        {
            GetSyncManager->GetOutputManager()->PrintHelp();
        }
    }
}
