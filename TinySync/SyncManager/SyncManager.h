#pragma once
#include "ISync.h"


class SyncManager : public ISync
{
public:

    void AddOrigin(::std::string origin_path) override;

    void AddTarget(::std::string target_path) override;

    void AddFilter(filter filter) override;

    void TransferFilesTarget() override;

    void CleanTarget() override;

    void BalanceFiles() override;

private:

    std::string origin;
    std::string target;

    filter filters;
    
};
