#pragma once

#include "ICommand.h"

class CommandBalance: public ICommand
{
    void Execute(std::vector<std::string> arguments, IController* controller) override;
};
