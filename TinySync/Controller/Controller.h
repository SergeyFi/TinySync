#pragma once

#include <memory>
#include <map>
#include <vector>

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

    bool ContainCommand(Command command, Commands& commands);

    std::vector<std::string> GetCommandArguments(Command command, Commands& commands);

    const std::map<Command, int> command_priority
    {
        {Command::help, 0},
        {Command::filter, 1},
        {Command::inverted_filter, 1},
        {Command::origin, 1},
        {Command::target, 1},
        {Command::clean, 2},
        {Command::balance, 3},
        {Command::sync, 3},
        
    };

    void CommandHelp(Commands& commands);
};
