#pragma once

#include "ICommand.h"

class CommandAddTarget : public ICommand
{
public:
    explicit CommandAddTarget(CommandType newName)
    {
        name = newName;
    }

private:
    void Execute(std::vector<std::string> arguments, IController* controller) override;

    CommandType GetName() override;

    CommandType name;
};
