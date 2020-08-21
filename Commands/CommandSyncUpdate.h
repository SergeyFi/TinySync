#pragma once

#include "CommandBase.h"

class CommandSyncUpdate : public CommandBase
{
    using CommandBase::CommandBase;

    void Execute(std::vector<std::string> arguments, IController* controller) override;
};