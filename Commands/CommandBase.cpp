#include "CommandBase.h"

int CommandBase::GetCommandPriority() const
{
    return commandPriority;
}

CommandsList CommandBase::GetCommandsList() const
{
    return commandsList;
}
