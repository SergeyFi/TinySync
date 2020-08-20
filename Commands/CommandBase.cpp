#include "CommandBase.h"

std::set<std::string> CommandBase::GetRawCommands() const
{
    return rawCommands;
}

CommandType CommandBase::GetName() const
{
    return name;
}
