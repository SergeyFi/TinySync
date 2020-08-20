#pragma once

#include <vector>
#include <string>
#include <set>
#include "IController.h"

class ICommand
{
public:

    virtual void Execute(std::vector<std::string> arguments, IController* controller) = 0;

    virtual CommandType GetName() const = 0;

    virtual std::set<std::string> GetRawCommands() const = 0;

    virtual int GetCommandPriority() const = 0;

};