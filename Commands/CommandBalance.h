#pragma once

#include "ICommand.h"

class CommandBalance: public ICommand
{
public:
    explicit CommandBalance(CommandType new_name)
    {
        name = new_name;
    }

private:
    void Execute(std::vector<std::string> arguments, IController* controller) override;

    CommandType GetName() override;

    CommandType name;
};
