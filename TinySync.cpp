#define tinySyncVersion "0.3a-4"

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

    CommandConstructor->AddCommand<CommandVersion>(
            {"-V", "--version"} ,"Version", tinySyncVersion, Priority(0), ArgCount(0), OutputManager.get());

    CommandConstructor->AddCommand<CommandAddOrigin>(
            {"-O", "--origin"} ,"Origin", Priority(1), ArgCount(1), SyncManager.get());

    CommandConstructor->AddCommand<CommandAddTarget>(
            {"-T", "--target"} ,"Target", Priority(1), ArgCount(1), SyncManager.get());

    CommandConstructor->AddCommand<CommandSync>(
            {"-S", "--sync"} ,"Sync", Priority(3), ArgCount(0), SyncManager.get());

    CommandConstructor->AddCommand<CommandBalance>(
            {"-B", "--balance"} ,"Balance", Priority(3), ArgCount(0), SyncManager.get());

    CommandConstructor->AddCommand<CommandCleanTarget>(
            {"-C", "--clean"} ,"Clean", Priority(2), ArgCount(0), SyncManager.get());

    CommandConstructor->AddCommand<CommandHelp>(
            {"-H", "--help"} ,"Help", Priority(0), ArgCount(0), OutputManager.get());

    CommandConstructor->AddCommand<CommandSyncUpdate>(
            {"-SU", "--syncUpdate"} ,"SyncUpdate", Priority(3), ArgCount(0), SyncManager.get());


    std::shared_ptr<ICommandExecutor> CommandExecutor{new class CommandExecutor(CommandConstructor.get())};

    std::shared_ptr<ICommandDecoder> CommandDecoder {new class CommandDecoder(CommandExecutor.get(), CommandConstructor.get())};

    CommandDecoder->AddRawData(argc, argv);

    return 0;
}
