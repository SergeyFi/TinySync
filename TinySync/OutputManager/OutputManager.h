#pragma once
#include "IOutputManager.h"

class OutputManager : public IOutputManager
{
public:

    void PrintCommand(Command& command) override;
};
