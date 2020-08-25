#pragma once

#include "ILogger.h"
#include <map>

class Logger : public ILogger
{
public:

    void Log(std::string log, LogType logType) override;

    static ILogger* GetLogger()
    {
        if (LoggerInstance == nullptr)
        {
            LoggerInstance = new Logger();
        }

        return LoggerInstance;
    };

private:
    const std::map<LogType, std::string> logStringName
            {
                    {LogType::notification,"Notice"},
                    {LogType::warning,"Warning"},
                    {LogType::error, "Error"}
            };

    static ILogger* LoggerInstance;

    Logger() = default;
};


