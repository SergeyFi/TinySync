#pragma once

#include "ICommand.h"
#include "CommandBase.h"

class CommandAddOrigin: public CommandBase
{
public:

    using CommandBase::CommandBase;

    void Execute(std::vector<std::string> arguments, IController* controller) override;
};
