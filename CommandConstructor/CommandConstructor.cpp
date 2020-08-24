
#include "CommandConstructor.h"


void CommandConstructor::AddCommand(std::set<std::string> commandArguments,std::function<ICommand*()> commandConstructor)
{
    commandsArguments.push_back(commandArguments);
    commandConstructors[std::move(commandArguments)] = std::move(commandConstructor);
}

ICommand* CommandConstructor::GetCommand(std::set<std::string>& commandFullName)
{
    if (commandConstructors.count(commandFullName) > 0)
    {
        auto Command = commandConstructors[commandFullName]();
        Command->SetCommandFullName(commandFullName);

        return Command;
    }

    return nullptr;
}

std::vector<std::set<std::string>> CommandConstructor::GetCommandsFullName()
{
    return commandsArguments;
}
