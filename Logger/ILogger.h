#pragma once

#include <string>

enum LogType
{
    notification,
    warning,
    error
};

class ILogger
{
public:
    virtual void Log(std::string log, LogType logType) = 0;
};

