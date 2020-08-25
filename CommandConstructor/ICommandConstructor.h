#pragma once

#include <functional>
#include <vector>
#include <set>

#include "../Commands/CommandBase.h"
#include "../DataTypes/DataTypes.h"

class ICommandConstructor
{
private:

    virtual void AddNewCommand(CFullName fullName ,CConstructor commandConstructor) = 0;

public:

    template<class CommandClass, class ... ConstructorArguments>
    void AddCommand(CFullName fullName, ConstructorArguments ... args)
    {
        auto newConstructor = [fullName, args...](std::vector<std::string> arg)
        {
            return new CommandClass{fullName, arg, args...};
        };

        AddNewCommand(fullName, newConstructor);
    }

    virtual ICommand* GetCommand(CFullName& commandFullName, CArg& arg) = 0;

    virtual std::vector<CFullName> GetCommandsFullNames() = 0;
};