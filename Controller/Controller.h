#pragma once

#include <memory>
#include <map>
#include <vector>

#include "IController.h"
#include "../InputManager/IInputManager.h"
#include "../OutputManager/IOutputManager.h"
#include "../SyncManager/ISync.h"
#include "IGetSyncManager.h"

class Controller : public IController, public IGetSyncManager
{
public:

    Controller(bool debug, std::shared_ptr<IInputManager>& Input_manager,
        std::shared_ptr<IOutputManager>& Output_manager, std::shared_ptr<ISync>& Sync_manager);

    void InputConsoleArgument(int argc, char* argv[]) override;

    void InputCommand(std::vector<Command> commands) override;

    bool debug;

    std::shared_ptr<ISync> GetSyncManager() override;

private:

    std::shared_ptr<IInputManager> Input_manager;
    std::shared_ptr<IOutputManager> Output_manager;
    std::shared_ptr<ISync> Sync_manager;

    const std::map<CommandType, int> command_priority
    {
        {CommandType::help,            0},
        {CommandType::filter,          1},
        {CommandType::inverted_filter, 1},
        {CommandType::origin,          1},
        {CommandType::target,          1},
        {CommandType::clean,           2},
        {CommandType::balance,         3},
        {CommandType::sync,            3},
        
    };

    void CommandHelp();

    void AddOrigin(std::string origin_path);

    void AddTarget(std::string target_path);

    void Sync();

    void Balance();

    void CleanTarget();

};
