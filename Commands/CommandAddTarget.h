#pragma once

#include "ICommand.h"

class CommandAddTarget : public ICommand
{
    void Execute(std::vector<std::string> arguments, IController* controller) override;
};
