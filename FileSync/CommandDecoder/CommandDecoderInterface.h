#pragma once

#include "Command.h"

class CommandDecoderInterface
{
    
public:

    virtual void AddRawData(int argc, char* argv[]) = 0;

    virtual std::vector<CommandArgument> GetCommands() = 0;
};
