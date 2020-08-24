#define tinySyncVersion "0.3a-3"

#include <memory>

#include "CommandExecutor/CommandExecutor.h"
#include "OutputManager/OutputManager.h"
#include "SyncManager/SyncManager.h"
#include "CommandConstructor/ICommandConstructor.h"
#include "CommandConstructor/CommandConstructor.h"
#include "Commands/CommandAddOrigin.h"
#include "Commands/CommandAddTarget.h"
#include "Commands/CommandSync.h"
#include "Commands/CommandBalance.h"
#include "Commands/CommandCleanTarget.h"
#include "Commands/CommandVersion.h"
#include "Commands/CommandHelp.h"
#include "Commands/CommandSyncUpdate.h"
#include "CommandDecoder/ICommandDecoder.h"
#include "CommandDecoder/CommandDecoder.h"

int main(int argc, char* argv[])
{
    std::shared_ptr<IOutputManager> OutputManager {new class OutputManager()};

    std::shared_ptr<ISync> SyncManager {new class SyncManager()};

    std::unique_ptr<ICommandConstructor> CommandConstructor {new class CommandConstructor()};

    CommandConstructor->AddCommand({"-V", "--version"}, [OutputManager]()
    {return new CommandVersion{"Version", tinySyncVersion, 0, 0, OutputManager.get()};});

    CommandConstructor->AddCommand({"-O", "--origin"}, [SyncManager]()
    {return new CommandAddOrigin{"Origin", 1, 1, SyncManager.get()};});

    CommandConstructor->AddCommand({"-T", "--target"}, [SyncManager]()
    {return new CommandAddTarget{"Target",1, 1, SyncManager.get()};});

    CommandConstructor->AddCommand({"-S", "--sync"}, [SyncManager]()
    {return new CommandSync{"Sync",3, 0, SyncManager.get()};});

    CommandConstructor->AddCommand({"-B", "--balance"}, [SyncManager]()
    {return new CommandBalance{"Balance", 3, 0, SyncManager.get()};});

    CommandConstructor->AddCommand({"-C", "--clean"}, [SyncManager]()
    {return new CommandCleanTarget{"Clean", 2, 0, SyncManager.get()};});

    CommandConstructor->AddCommand({"-H", "--help"}, [OutputManager]()
    {return new CommandHelp{"Help",0, 0, OutputManager.get()};});

    CommandConstructor->AddCommand({"-SU", "--syncUpdate"}, [SyncManager]()
    {return new CommandSyncUpdate{"SyncUpdate",3, 0, SyncManager.get()};});

    std::shared_ptr<ICommandExecutor> CommandExecutor{new class CommandExecutor(CommandConstructor.get())};

    std::shared_ptr<ICommandDecoder> CommandDecoder {new class CommandDecoder(CommandExecutor.get(), CommandConstructor.get())};

    CommandDecoder->AddRawData(argc, argv);

    return 0;
}
