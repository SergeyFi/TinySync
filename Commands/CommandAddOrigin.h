#pragma once

#include "ICommand.h"

class CommandAddOrigin: public ICommand
{
    void Execute(std::vector<std::string> arguments, IController* controller) override;
};
