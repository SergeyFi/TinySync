#pragma once

#include <vector>
#include <string>
#include <set>
#include "../CommandExecutor/ICommandExecutor.h"

class ICommand
{
public:

    virtual void Execute() = 0;

    virtual void AddCommandArguments(std::vector<std::string> arguments) = 0;

    virtual CommandFullName GetCommandsList() const = 0;

    virtual int GetCommandPriority() const = 0;

    virtual std::string GetCommandName() const = 0;

    virtual void SetCommandFullName(std::set<std::string> fullName) = 0;

};