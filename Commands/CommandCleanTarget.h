#pragma once

#include "ICommand.h"

class CommandCleanTarget : public ICommand
{
    void Execute(std::vector<std::string> arguments, IController* controller) override;
};
