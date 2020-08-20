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
#include "Commands/CommandVersion.h"
#include "Commands/CommandHelp.h"

int main(int argc, char* argv[])
{
    const std::string programVersion = "0.2a";

    std::shared_ptr<IInputManager> Input_manager {new InputManager()};

    std::shared_ptr<IOutputManager> Output_manager {new OutputManager()};

    std::shared_ptr<ISync> Sync_manager {new SyncManager()};

    // Set commands
    std::vector<std::shared_ptr<ICommand>> commands;

    commands.emplace_back(new CommandAddOrigin{1, {"-O", "--origin"}, 1});

    commands.emplace_back(new CommandAddTarget{1, {"-T", "--target"}, 1});

    commands.emplace_back(new CommandSync{3, {"-S", "--sync"}, 0});

    commands.emplace_back(new CommandBalance{3, {"-B", "--balance"}, 0});

    commands.emplace_back(new CommandCleanTarget{2, {"-C", "--clean"}, 0});

    commands.emplace_back(new CommandVersion{programVersion, 0, {"-V", "--version"}, 0});

    commands.emplace_back(new CommandHelp{0, {"-H", "--help"}, 0});


    std::shared_ptr<IController> Sync_controller
    {new Controller(true ,Input_manager, Output_manager, Sync_manager, commands)};

    Input_manager->AddController(Sync_controller);

    Sync_controller->InputConsoleArgument(argc, argv);

    return 0;
}
