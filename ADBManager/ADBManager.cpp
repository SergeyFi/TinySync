#include "ADBManager.h"

#include <iostream>

FilesData ADBManager::CreateFileLocalFileList(const std::string& path) const
{
    namespace fs = std::filesystem;

    FilesData data;

    for (const auto & entry : fs::directory_iterator(path))
    {
        data[entry.path().string()] = {entry.last_write_time()};
    }

    return data;
}
