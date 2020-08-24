#pragma once

#include <functional>
#include <vector>
#include <set>

#include "../Commands/CommandBase.h"

class ICommandConstructor
{
public:

    virtual void AddCommand(std::set<std::string> commandArguments,std::function<ICommand*()> commandConstructor) = 0;

    virtual ICommand* GetCommand(std::set<std::string>& commandArguments) = 0;

    virtual std::vector<std::set<std::string>> GetCommandsFullName() = 0;
};