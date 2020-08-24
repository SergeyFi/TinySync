#pragma once

#include "ICommand.h"

#include "../Logger/GetLogger.h"

class CommandBase : public ICommand
{

public:

    CommandBase(std::string newCommandName, int priority, int argc)
    {
        commandPriority = priority;
        commandArgumentCount = argc;
        commandName = std::move(newCommandName);
    }

    CommandFullName GetCommandsList() const override;

    int GetCommandPriority() const override;

    std::string GetCommandName() const override;

    void AddCommandArguments(std::vector<std::string> arguments) override;

    void SetCommandFullName(std::set<std::string> fullName) override;

protected:

    std::string commandName;

    CommandFullName commandsList;

    int commandPriority;

    int commandArgumentCount;

    std::vector<std::string> commandArguments;

    void ArgumentCountWarning(int argumentsGiven);
};
