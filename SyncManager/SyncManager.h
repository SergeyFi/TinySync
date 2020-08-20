#pragma once
#include "ISync.h"


class SyncManager : public ISync
{
public:

    void AddOrigin(::std::string origin_path) override;

    void AddTarget(::std::string target_path) override;

    void AddFilter(filter filter) override;

    void Sync() override;

    void CleanTarget() override;

    void BalanceFiles() override;

private:

    std::string origin;
    std::string target;

    bool OriginPathCheck();

    bool TargetPathCheck();

    filter filters;

    void UnsafeSync(const std::string origin_path, const std::string target_path);
    
};
