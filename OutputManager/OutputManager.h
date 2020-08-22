#pragma once
#include "IOutputManager.h"

class OutputManager : public IOutputManager
{
public:

    void PrintHelp() override;

    void PrintVersion(std::string version) const override;
};
