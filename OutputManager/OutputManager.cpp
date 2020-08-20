#include "OutputManager.h"

#include <iostream>
#include <ostream>

void OutputManager::PrintHelp()
{
    std::cout << "Help" << std::endl;
}

void OutputManager::PrintVesrion(std::string version) const
{
    std::cout << "TinySync v" << version << std::endl;
}
