#include "SyncManager.h"
#include "../Logger/GetLogger.h"


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
    if (OriginTargetCheck())
    {
        bool safe_sync = false;

        if (!safe_sync)
        {
            UnsafeSync();
        }
    }
}

void SyncManager::CleanTarget()
{
    
}

void SyncManager::BalanceFiles()
{
    
}

bool SyncManager::OriginTargetCheck()
{
    if (target.empty())
    {
        GetLogger::LoggerGet()->Log("Target path is empty.", LogType::error);

       return false;
    }

    if (origin.empty())
    {
        GetLogger::LoggerGet()->Log("Origin path is empty.", LogType::error);

        return false;
    }

    return true;
}

void SyncManager::UnsafeSync()
{

}
