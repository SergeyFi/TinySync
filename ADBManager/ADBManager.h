#pragma once

#include "IADBManager.h"
#include "FileData.h"

#include <filesystem>
#include <map>

using FilesData = std::map<std::string , FileData>;

class ADBManager : IADBManager
{
private:

    FilesData CreateFileLocalFileList(const std::string& path) const;
};
