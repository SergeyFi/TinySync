#pragma once
#include "IOutputManager.h"

class OutputManager : public IOutputManager
{
public:

    void PrintHelp() override;

    void PrintVesrion(std::string version) const override;
};
