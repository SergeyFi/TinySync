#include "SyncManager.h"

void SyncManager::AddOrigin(::std::string origin_path)
{
    origin = origin_path;
}

void SyncManager::AddTarget(::std::string target_path)
{
    target = target_path;
}

void SyncManager::AddFilter(filter filter)
{
    filters = filter;
}

void SyncManager::TransferFilesTarget()
{
    
}

void SyncManager::CleanTarget()
{
    
}

void SyncManager::BalanceFiles()
{
    
}
