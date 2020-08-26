#pragma once

#include <vector>
#include <string>
#include <set>

#include "../CommandExecutor/ICommandExecutor.h"
#include "../DataTypes/DataTypes.h"

class ICommand
{
public:

    virtual void Execute() = 0;

    virtual void AddCommandArguments(std::vector<std::string> arguments) = 0;

    virtual CFullName GetCommandsList() const = 0;

    virtual int GetCommandPriority() const = 0;

    virtual CName GetCommandName() const = 0;

    virtual void SetCommandFullName(CFullName fullName) = 0;

};