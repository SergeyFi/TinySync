#pragma once

#include "CommandBase.h"
#include "../Controller/IGetOutputManager.h"

class CommandHelp: public CommandBase
{
    using CommandBase::CommandBase;

    void Execute(std::vector<std::string> arguments, IController* controller) override;
};
