#include "OutputManager.h"

#include <iostream>
#include <iterator>
#include <ostream>

void OutputManager::PrintCommand(Commands& commands)
{
    for (int i = 0; i < commands.commands.size(); ++i)
    {
        std::cout << "Command: ";
        
        for (auto argument : commands.arguments[i])
        {
            std::cout << argument << " ";
        }

        std::cout << std::endl;
    }
}

void OutputManager::PrintHelp()
{
    std::cout << "Help" << std::endl;
}
