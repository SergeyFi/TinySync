#pragma once

#include <functional>
#include <map>

#include "ICommandConstructor.h"
#include "../Commands/CommandBase.h"


class CommandConstructor: public ICommandConstructor
{
public:
    void AddCommand(std::set<std::string> commandArguments,std::function<ICommand*()> commandConstructor) override;

    ICommand* GetCommand(std::set<std::string>& commandFullName) override;

    std::vector<std::set<std::string>> GetCommandsFullName() override;

private:

    std::map<std::set<std::string> ,std::function<ICommand*()>> commandConstructors;

    std::vector<std::set<std::string>> commandsArguments;
};

