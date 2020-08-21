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
#include "Commands/CommandSyncUpdate.h"

int main(int argc, char* argv[])
{
    const std::string programVersion = "0.3a-2";

    std::shared_ptr<IInputManager> InputManager {new class InputManager()};

    std::shared_ptr<IOutputManager> OutputManager {new class OutputManager()};

    std::shared_ptr<ISync> SyncManager {new class SyncManager()};

    // Set commands
    std::vector<std::shared_ptr<ICommand>> commands;

    commands.emplace_back(new CommandAddOrigin{"Origin", 1, {"-O", "--origin"}, 1, SyncManager.get()});

    commands.emplace_back(new CommandAddTarget{"Target",1, {"-T", "--target"}, 1, SyncManager.get()});

    commands.emplace_back(new CommandSync{"Sync",3, {"-S", "--sync"}, 0, SyncManager.get()});

    commands.emplace_back(new CommandBalance{"Balance", 3, {"-B", "--balance"}, 0, SyncManager.get()});

    commands.emplace_back(new CommandCleanTarget{"Clean", 2, {"-C", "--clean"}, 0, SyncManager.get()});

    commands.emplace_back(new CommandVersion{"Version", programVersion, 0, {"-V", "--version"}, 0, OutputManager.get()});

    commands.emplace_back(new CommandHelp{"Help",0, {"-H", "--help"}, 0, OutputManager.get()});

    commands.emplace_back(new CommandSyncUpdate{"SyncUpdate",3, {"-SU", "--syncUpdate"}, 0, SyncManager.get()});


    std::shared_ptr<IController> Sync_controller{new Controller(commands)};

    InputManager->AddController(Sync_controller);

    InputManager->InputArguments(argc, argv);

    return 0;
}
