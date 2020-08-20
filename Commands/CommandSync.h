#pragma once

#include "ICommand.h"
#include "CommandBase.h"

class CommandSync : public CommandBase
{
public:

    using CommandBase::CommandBase;

    void Execute(std::vector<std::string> arguments, IController* controller) override;
};