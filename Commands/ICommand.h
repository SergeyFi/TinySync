#pragma once

#include <vector>
#include <string>
#include <set>
#include "../CommandExecutor/ICommandExecutor.h"

class ICommand
{
public:

    virtual void Execute(std::vector<std::string> arguments) = 0;

    virtual CommandsList GetCommandsList() const = 0;

    virtual int GetCommandPriority() const = 0;

    virtual std::string GetCommandName() const = 0;

};