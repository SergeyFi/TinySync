#include "CommandBase.h"

int CommandBase::GetCommandPriority() const
{
    return commandPriority;
}

CFullName CommandBase::GetCommandsList() const
{
    return commandFullName;
}

void CommandBase::ArgumentCountWarning(int argumentsGiven, std::string newCommandName)
{
    if (newCommandName.empty())
    {
        newCommandName = commandName;
    }

    if (commandArgumentCount != argumentsGiven)
    {
        Logger::GetLogger()->Log("For command '" + newCommandName + "' expected " + std::to_string(commandArgumentCount)
        + " arguments, given " + std::to_string(argumentsGiven), LogType::warning);
    }
}

CName CommandBase::GetCommandName() const
{
    return commandName;
}

void CommandBase::AddCommandArguments(std::vector<std::string> arguments)
{
    commandArguments = std::move(arguments);
}

void CommandBase::SetCommandFullName(std::set<std::string> fullName)
{

}
