#pragma once

#include <functional>
#include <vector>
#include <set>

#include "../Commands/CommandBase.h"

class ICommandConstructor
{
private:

    virtual void AddNewCommand(std::set<std::string> fullName ,
                               std::function<ICommand*(std::vector<std::string> arg)> commandConstructor) = 0;

public:

    template<class CommandClass, class ... ConstructorArguments>
    void AddCommand(std::set<std::string> fullName,ConstructorArguments ... args)
    {
        auto newConstructor = [fullName, args...](std::vector<std::string> arg)
        {
            return new CommandClass{fullName, arg, args...};
        };

        AddNewCommand(fullName, newConstructor);
    }

    virtual ICommand* GetCommand(std::set<std::string>& commandArguments, std::vector<std::string>& arg) = 0;

    virtual std::vector<std::set<std::string>> GetCommandsFullName() = 0;
};