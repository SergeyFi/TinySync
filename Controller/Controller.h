#pragma once

#include <memory>
#include <map>

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
        std::vector<std::shared_ptr<ICommand>>& New_Commands);

    void InputConsoleArgument(int argc, char* argv[]) override;

    void InputCommand(std::vector<Command> commands) override;

    bool debug;

    std::shared_ptr<ISync> GetSyncManager() override;

    const std::map<CommandsList, std::shared_ptr<ICommand>>& GetCommandsMap() const override;

    std::shared_ptr<IOutputManager> GetOutputManager() override;

private:

    std::shared_ptr<IInputManager> Input_manager;
    std::shared_ptr<IOutputManager> Output_manager;
    std::shared_ptr<ISync> Sync_manager;

    std::vector<std::shared_ptr<ICommand>> Commands;
    std::map<CommandsList, std::shared_ptr<ICommand>> CommandsMap;

    void GenerateCommandsMap();

};
