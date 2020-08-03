#pragma once
#include "InputManagerInterface.h"

class InputManager : InputManagerInterface
{
    
public:

    void AddRawCommands(int argc, char* argv[]) override;

    
    
};
