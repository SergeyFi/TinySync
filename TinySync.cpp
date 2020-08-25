#define tinySyncVersion "0.3a-4"

#include <memory>

#include "CommandExecutor/CommandExecutor.h"
#include "OutputManager/OutputManager.h"
#include "SyncManager/SyncManager.h"
#include "CommandConstructor/CommandConstructor.h"
#include "CommandDecoder/ICommandDecoder.h"
#include "CommandDecoder/CommandDecoder.h"

#include "ComandInitialization.h"

int main(int argc, char* argv[])
{
    std::shared_ptr<IOutputManager> OutputManager {new class OutputManager()};

    std::shared_ptr<ISync> SyncManager {new class SyncManager()};

    std::unique_ptr<ICommandConstructor> CommandConstructor {new class CommandConstructor()};

    std::shared_ptr<ICommandExecutor> CommandExecutor{new class CommandExecutor(CommandConstructor.get())};

    std::shared_ptr<ICommandDecoder> CommandDecoder {new class CommandDecoder(CommandExecutor.get(), CommandConstructor.get())};

    InitCommands(CommandConstructor.get(),SyncManager.get(), OutputManager.get());

    CommandDecoder->AddRawData(argc, argv);

    return 0;
}
