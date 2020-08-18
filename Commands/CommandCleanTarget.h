#pragma once

#include "ICommand.h"

class CommandCleanTarget : public ICommand
{
public:
    explicit CommandCleanTarget(CommandType newName)
    {
        name = newName;
    }

private:
    void Execute(std::vector<std::string> arguments, IController* controller) override;

    CommandType GetName() override;

    CommandType name;
};
