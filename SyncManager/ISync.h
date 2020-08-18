#pragma once
#include <string>
#include "Filter.h"

class ISync
{
public:

    virtual void AddOrigin(std::string origin_path) = 0;

    virtual void AddTarget(std::string target_path) = 0;

    virtual void AddFilter(filter filter) = 0;

    virtual void Sync() = 0;

    virtual void CleanTarget() = 0;

    virtual void BalanceFiles() = 0;
};
