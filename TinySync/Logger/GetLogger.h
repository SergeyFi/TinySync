#pragma once

#include "ILogger.h"
#include "Logger.h"

class GetLogger
{
public:
    static ILogger* LoggerGet()
    {
        if (LoggerInstance == nullptr)
        {
            LoggerInstance = new Logger();
        }

        return LoggerInstance;
    };

private:

    static ILogger* LoggerInstance;

    GetLogger() = default;
};