
#include "CommandConstructor.h"


ICommand* CommandConstructor::GetCommand(std::set<std::string>& commandFullName, std::vector<std::string>& arg)
{
    if (commandConstructors.count(commandFullName) > 0)
    {
        auto Command = commandConstructors[commandFullName](arg);

        return Command;
    }

    return nullptr;
}

std::vector<std::set<std::string>> CommandConstructor::GetCommandsFullName()
{
    return commandsArguments;
}

void CommandConstructor::AddNewCommand
(std::set<std::string> commandFullName ,std::function<ICommand*(std::vector<std::string> arg)> commandConstructor)
{
    commandConstructors[commandFullName] = std::move(commandConstructor);
    commandsArguments.push_back(std::move(commandFullName));
}
