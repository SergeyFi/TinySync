#include "CommandBase.h"

int CommandBase::GetCommandPriority() const
{
    return commandPriority;
}

CommandsList CommandBase::GetCommandsList() const
{
    return commandsList;
}

void CommandBase::ArgumentCountWarning(int argumentsGiven)
{
    if (commandArgumentCount != argumentsGiven)
    {
        GetLogger::LoggerGet()->Log("Expected " + std::to_string(commandArgumentCount)
        + " arguments, given " + std::to_string(argumentsGiven), LogType::warning);
    }
}
