#include "CommandExecutor.h"

#include <algorithm>

CommandExecutor::CommandExecutor(ICommandConstructor* NewCommandConstructor)
{
    CommandConstructor = NewCommandConstructor;
}

void CommandExecutor::InputCommand(std::vector<Command> commands)
{
    std::vector<ICommand*> commandsToExecute;

    for (auto& command : commands)
    {
        commandsToExecute.push_back(CommandConstructor->GetCommand(command.commandFullName));
        commandsToExecute.back()->AddCommandArguments(command.arguments);
    }

    std::sort(commandsToExecute.begin(), commandsToExecute.end(), [](const ICommand* a, const ICommand* b)
    {
        return a->GetCommandPriority() < b->GetCommandPriority();
    });

    for (auto& command : commandsToExecute)
    {
        command->Execute();
    }

}
