#include "SyncManager.h"
#include "../Logger/GetLogger.h"
#include <filesystem>


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
        UnsafeSync(origin, target);
    }
}

void SyncManager::CleanTarget()
{
    namespace fs = std::filesystem;

    if (!target.empty())
    {
        fs::remove(target);
    }
    else
    {
        GetLogger::LoggerGet()->Log("Target path is empty.", LogType::error);
    }
}

void SyncManager::BalanceFiles()
{
    UnsafeSync(origin, target);
    UnsafeSync(target, origin);
}

bool SyncManager::OriginTargetCheck()
{
    if (target.empty() || origin.empty())
    {
        if (target.empty())
        {
            GetLogger::LoggerGet()->Log("Target path is empty.", LogType::error);
        }

        if (origin.empty())
        {
            GetLogger::LoggerGet()->Log("Origin path is empty.", LogType::error);
        }

       return false;
    }

    return true;
}

void SyncManager::UnsafeSync(const std::string origin_path, const std::string target_path)
{
    namespace fs = std::filesystem;

    fs::copy(origin_path, target_path, fs::copy_options::skip_existing | fs::copy_options::recursive);
}
