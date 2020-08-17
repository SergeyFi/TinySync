#pragma once

#include "ILogger.h"
#include <map>

class Logger : public ILogger
{
public:

    void Log(std::string log, LogType logType) override;

private:
    const std::map<LogType, std::string> logStringName
            {
                    {LogType::notification,"Notice"},
                    {LogType::warning,"Warning"},
                    {LogType::error, "Error"}
            };
};


