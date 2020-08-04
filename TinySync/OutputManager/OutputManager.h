#pragma once
#include "IOutputManager.h"

class OutputManager : public IOutputManager
{
public:

    void PrintCommand(Commands& commands) override;
};
