#pragma once

#include <memory>
#include "IController.h"
#include "../InputManager/IInputManager.h"
#include "../OutputManager/IOutputManager.h"
#include "../SyncManager/ISync.h"

class Controller : public IController
{
public:

    Controller(bool debug, std::shared_ptr<IInputManager> Input_manager,
        std::shared_ptr<IOutputManager> Output_manager, std::shared_ptr<ISync> Sync_manager);

    void InputConsoleArgument(int argc, char* argv[]) override;

    void InputCommand(Commands command) override;

    bool debug;

private:

    std::shared_ptr<IInputManager> Input_manager;
    std::shared_ptr<IOutputManager> Output_manager;
    std::shared_ptr<ISync> Sync_manager;
};
