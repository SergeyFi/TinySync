#pragma once

#include "ICommand.h"

#include "../Logger/Logger.h"
#include "Priority.h"
#include "ArgumentCount.h"
#include "../DataTypes/DataTypes.h"

class CommandBase : public ICommand
{

public:

    explicit CommandBase(CName newCommandName, CArg arguments, CFullName fullName, Priority priority, ArgCount argc)
    {
        commandPriority = priority.priority;
        commandArgumentCount = argc.count;
        commandName = std::move(newCommandName);
        commandFullName = std::move(fullName);
        commandArguments = std::move(arguments);
    }

    CommandFullName GetCommandsList() const override;

    int GetCommandPriority() const override;

    std::string GetCommandName() const override;

    void AddCommandArguments(std::vector<std::string> arguments) override;

    void SetCommandFullName(std::set<std::string> fullName) override;

protected:

    CName commandName;

    CFullName commandFullName;

    int commandPriority;

    int commandArgumentCount;

    CArg commandArguments;

    void ArgumentCountWarning(int argumentsGiven, std::string newCommandName = "");
};
