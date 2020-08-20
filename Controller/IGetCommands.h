#pragma once

#include <map>
#include <string>
#include <memory>
#include "../Commands/ICommand.h"

class IGetCommands
{
public:
    virtual const std::map<CommandsList, std::shared_ptr<ICommand>>& GetCommandsMap() const = 0;
};