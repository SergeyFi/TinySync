#include <memory>

#include "Controller/Controller.h"
#include "InputManager/InputManager.h"
#include "OutputManager/OutputManager.h"
#include "SyncManager/SyncManager.h"
#include "Commands/CommandAddOrigin.h"
#include "Commands/CommandAddTarget.h"
#include "Commands/CommandSync.h"
#include "Commands/CommandBalance.h"
#include "Commands/CommandCleanTarget.h"

int main(int argc, char* argv[])
{
    std::shared_ptr<IInputManager> Input_manager {new InputManager()};

    std::shared_ptr<IOutputManager> Output_manager {new OutputManager()};

    std::shared_ptr<ISync> Sync_manager {new SyncManager()};

    // Set commands
    std::map<CommandType, std::shared_ptr<ICommand>> commands;
    commands.insert(std::make_pair(
            CommandType::origin, new CommandAddOrigin(CommandType::origin, {"-O", "--origin"})));

    commands.insert(std::make_pair(
            CommandType::target, new CommandAddTarget(CommandType::target, {"-T", "--target"})));

    commands.insert(std::make_pair(
            CommandType::sync, new CommandSync(CommandType::sync, {"-S", "--sync"})));

    commands.insert(std::make_pair(
            CommandType::balance, new CommandBalance(CommandType::balance, {"-B", "--balance"})));

    commands.insert(std::make_pair(
            CommandType::clean, new CommandCleanTarget(CommandType::clean, {"-C", "--clean"})));

    std::shared_ptr<IController> Sync_controller
    {new Controller(true ,Input_manager, Output_manager, Sync_manager, commands)};

    Input_manager->AddController(Sync_controller);

    Sync_controller->InputConsoleArgument(argc, argv);

    return 0;
}
