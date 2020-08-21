#include "OutputManager.h"

#include <iostream>
#include <ostream>

void OutputManager::PrintHelp()
{
    std::cout << "Set path to origin: -O your_path or --origin your_path" << std::endl;
    std::cout << "Set path to target: -T your_path or -- target your_path" << std::endl;
    std::cout << "Sync: -S or --sync" << std::endl;
    std::cout << "Sync with update old files: -SU or --syncUpdate" << std::endl;
    std::cout << "Balance: -B or --balance" << std::endl;
    std::cout << "Clean: -C or --clean" << std::endl;
    std::cout << "Current version: -V or --version" << std::endl;
}

void OutputManager::PrintVesrion(std::string version) const
{
    std::cout << "TinySync v" << version << std::endl;
}
