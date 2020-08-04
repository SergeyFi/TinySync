#pragma once
#include <string>
#include <vector>
#include "Filter.h"

class SyncInterface
{
public:

    virtual void TransferFiles(std::string origin_path, filter filter) = 0;

    virtual void CleanTarget(std::string target_path, filter filter) = 0;

    virtual void BalanceFiles(std::string origin_path, std::string target_path, filter filter) = 0;
};
