
#include "CommandConstructor.h"


ICommand* CommandConstructor::GetCommand(CFullName& commandFullName, CArg& arg)
{
    if (commandConstructors.count(commandFullName) > 0)
    {
        auto Command = commandConstructors[commandFullName](arg);

        return Command;
    }

    return nullptr;
}

std::vector<CFullName> CommandConstructor::GetCommandsFullNames()
{
    return commandsFullNames;
}

void CommandConstructor::AddNewCommand
(CFullName commandFullName, CConstructor commandConstructor)
{
    commandConstructors[commandFullName] = std::move(commandConstructor);
    commandsFullNames.push_back(std::move(commandFullName));
}
