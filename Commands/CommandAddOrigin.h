#pragma once

#include "ICommand.h"

class CommandAddOrigin: public ICommand
{
public:
    explicit CommandAddOrigin(CommandType newName)
    {
        name = newName;
    }

private:

    void Execute(std::vector<std::string> arguments, IController* controller) override;

    CommandType GetName() override;

    CommandType name;
};
