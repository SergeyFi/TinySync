#include "CommandBase.h"

int CommandBase::GetCommandPriority() const
{
    return commandPriority;
}

CommandFullName CommandBase::GetCommandsList() const
{
    return commandFullName;
}

void CommandBase::ArgumentCountWarning(int argumentsGiven)
{
    if (commandArgumentCount != argumentsGiven)
    {
        GetLogger::LoggerGet()->Log("For command '" + commandName + "' expected " + std::to_string(commandArgumentCount)
        + " arguments, given " + std::to_string(argumentsGiven), LogType::warning);
    }
}

std::string CommandBase::GetCommandName() const
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
