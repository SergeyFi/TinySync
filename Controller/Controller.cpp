#include "Controller.h"

#include <algorithm>

Controller::Controller(std::vector<std::shared_ptr<ICommand>>& New_Commands)
{
    Commands = New_Commands;

    GenerateCommandsMap();
}

void Controller::InputCommand(std::vector<Command> commands)
{
    std::sort(commands.begin(), commands.end(), [this](const Command& a, const Command& b)
    {
        return CommandsMap[a.commandName]->GetCommandPriority() < CommandsMap[b.commandName]->GetCommandPriority();
    });

    for (const auto& command : commands)
    {
        CommandsMap[command.commandName]->Execute(command.arguments, this);
    }
}

const std::map<std::string, std::shared_ptr<ICommand>>& Controller::GetCommandsMap() const
{
    return CommandsMap;
}

void Controller::GenerateCommandsMap()
{
    for (const auto& command : Commands)
    {
        CommandsMap[command->GetCommandName()] = command;
    }
}
