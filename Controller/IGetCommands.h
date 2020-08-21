#pragma once

#include <map>
#include <string>
#include <memory>
#include "../Commands/ICommand.h"

class IGetCommands
{
public:
    virtual const std::map<std::string , std::shared_ptr<ICommand>>& GetCommandsMap() const = 0;
};