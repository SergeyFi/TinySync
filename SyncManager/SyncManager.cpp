#include "SyncManager.h"
#include "../Logger/Logger.h"
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

void SyncManager::Sync()
{
    UnsafeSync(origin, target);
}

void SyncManager::CleanTarget()
{
    if (TargetPathCheck())
    {
        namespace fs = std::filesystem;

        std::error_code error;
        fs::remove_all(target, error);

        if (error)
        {
            Logger::GetLogger()->Log(error.message(), LogType::error);
        }
    }
}

void SyncManager::BalanceFiles()
{
    UnsafeSync(origin, target);
    UnsafeSync(target, origin);
}

bool SyncManager::OriginPathCheck()
{
    if (origin.empty())
    {
        Logger::GetLogger()->Log("Origin path is empty.", LogType::error);
        return false;
    }

    namespace fs = std::filesystem;

    std::error_code error;
    if (!fs::exists(origin, error))
    {
        Logger::GetLogger()->Log("Origin path is incorrect", LogType::error);
        return false;
    }

    return true;
}

void SyncManager::UnsafeSync(const std::string origin_path, const std::string target_path)
{
    bool targetCheck = TargetPathCheck();
    bool originCheck = OriginPathCheck();

    if (targetCheck && originCheck)
    {
        namespace fs = std::filesystem;

        fs::copy(origin_path, target_path, fs::copy_options::skip_existing | fs::copy_options::recursive);
    }
}

bool SyncManager::TargetPathCheck()
{
    if (target.empty())
    {
        Logger::GetLogger()->Log("Target path is empty.", LogType::error);
        return false;
    }

    namespace fs = std::filesystem;

    std::error_code error;
    if (!fs::exists(target, error))
    {
        Logger::GetLogger()->Log("Target path is incorrect.", LogType::error);
        return false;
    }

    return true;
}

void SyncManager::SyncUpdate()
{
    bool targetCheck = TargetPathCheck();
    bool originCheck = OriginPathCheck();

    if (targetCheck && originCheck)
    {
        namespace fs = std::filesystem;

        fs::copy(origin, target, fs::copy_options::update_existing | fs::copy_options::recursive);
    }
}
