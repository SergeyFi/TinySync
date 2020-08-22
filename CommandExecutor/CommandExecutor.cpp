#include "CommandExecutor.h"

#include <algorithm>

CommandExecutor::CommandExecutor(std::vector<std::shared_ptr<ICommand>>& NewCommands)
{
    Commands = NewCommands;

    GenerateCommandsMap();
}

void CommandExecutor::InputCommand(std::vector<Command> commands)
{
    std::sort(commands.begin(), commands.end(), [this](const Command& a, const Command& b)
    {
        return CommandsMap[a.commandName]->GetCommandPriority() < CommandsMap[b.commandName]->GetCommandPriority();
    });

    for (const auto& command : commands)
    {
        CommandsMap[command.commandName]->Execute(command.arguments);
    }
}

const std::map<std::string, std::shared_ptr<ICommand>>& CommandExecutor::GetCommandsMap() const
{
    return CommandsMap;
}

void CommandExecutor::GenerateCommandsMap()
{
    for (const auto& command : Commands)
    {
        CommandsMap[command->GetCommandName()] = command;
    }
}
