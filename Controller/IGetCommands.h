#pragma once

#include <map>
#include <string>
#include <memory>
#include "../Commands/ICommand.h"

class IGetCommands
{
public:
    virtual std::map<CommandType, std::shared_ptr<ICommand>> GetCommands() const = 0;
};