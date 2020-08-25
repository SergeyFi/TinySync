#pragma once

#include "ICommand.h"

#include "../Logger/GetLogger.h"
#include "Priority.h"
#include "ArgumentCount.h"

class CommandBase : public ICommand
{

public:

    explicit CommandBase(std::string newCommandName, std::vector<std::string> arguments, std::set<std::string> fullName,
                         Priority priority, ArgCount argc)
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

    std::string commandName;

    CommandFullName commandFullName;

    int commandPriority;

    int commandArgumentCount;

    std::vector<std::string> commandArguments;

    void ArgumentCountWarning(int argumentsGiven);
};
