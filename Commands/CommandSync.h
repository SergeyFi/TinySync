#pragma once

#include "ICommand.h"

class CommandSync : public ICommand
{
public:
    explicit CommandSync(CommandType newName)
    {
        name = newName;
    }

private:
    void Execute(std::vector<std::string> arguments, IController* controller) override;

    CommandType GetName() override;

    CommandType name;
};
