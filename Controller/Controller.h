#pragma once

#include <memory>
#include <map>
#include <vector>

#include "IController.h"
#include "../InputManager/IInputManager.h"
#include "../OutputManager/IOutputManager.h"
#include "../SyncManager/ISync.h"
#include "IGetSyncManager.h"
#include "../Commands/ICommand.h"
#include "IGetCommands.h"
#include "IGetOutputManager.h"

class Controller : public IController, public IGetSyncManager
        , public IGetCommands, public IGetOutputManager
{
public:

    Controller(bool debug, std::shared_ptr<IInputManager>& Input_manager,
        std::shared_ptr<IOutputManager>& Output_manager, std::shared_ptr<ISync>& Sync_manager,
        std::map<CommandType, std::shared_ptr<ICommand>>& New_Commands);

    void InputConsoleArgument(int argc, char* argv[]) override;

    void InputCommand(std::vector<Command> commands) override;

    bool debug;

    std::shared_ptr<ISync> GetSyncManager() override;

    std::map<CommandType, std::shared_ptr<ICommand>> GetCommands() const override;

    std::shared_ptr<IOutputManager> GetOutputManager() override;

private:

    std::shared_ptr<IInputManager> Input_manager;
    std::shared_ptr<IOutputManager> Output_manager;
    std::shared_ptr<ISync> Sync_manager;

    std::map<CommandType, std::shared_ptr<ICommand>> Commands;

};
