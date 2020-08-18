#pragma once

#include <vector>
#include <string>
#include "IController.h"

class ICommand
{
public:

    virtual void Execute(std::vector<std::string> arguments, IController* controller) = 0;
    virtual CommandType GetName() = 0;
};