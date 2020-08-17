﻿#pragma once

#include "../InputManager/CommandDecoder/Command.h"

class IOutputManager
{
public:

    virtual void PrintCommand(Commands& commands) = 0;

    virtual void PrintHelp() = 0;
};