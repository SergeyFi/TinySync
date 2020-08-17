#include "Logger.h"

#include <iostream>
#include <fstream>



void Logger::Log(std::string log, LogType logType)
{
    std::cout << logStringName.find(logType)->second << ": " << log << std::endl;

    std::ofstream LogFile;
    LogFile.open("log.txt", std::ios_base::app);

    LogFile << logStringName.find(logType)->second << ": " << log << std::endl;
    LogFile.close();
}
