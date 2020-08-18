#pragma once

#include "ICommand.h"

class CommandSync : public ICommand
{
    void Execute(std::vector<std::string> arguments, IController* controller) override;
};
