#pragma once

#include <string>

class InputManagerInterface
{
    
public:
    
    virtual void InputData() = 0;

    virtual std::string GetRawData() = 0;
};
