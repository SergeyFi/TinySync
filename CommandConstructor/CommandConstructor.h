#pragma once

#include <functional>
#include <map>

#include "ICommandConstructor.h"
#include "../Commands/CommandBase.h"


class CommandConstructor: public ICommandConstructor
{
public:

    ICommand* GetCommand(std::set<std::string>& commandFullName, std::vector<std::string>& arg) override;

    std::vector<std::set<std::string>> GetCommandsFullName() override;

    void AddNewCommand(std::set<std::string> commandFullName ,
                       std::function<ICommand*(std::vector<std::string> arg)> commandConstructor) override;

private:

    std::map<std::set<std::string> ,std::function<ICommand*(std::vector<std::string> arg)>> commandConstructors;

    std::vector<std::set<std::string>> commandsArguments;


};

