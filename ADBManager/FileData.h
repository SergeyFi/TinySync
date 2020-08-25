#pragma once

#include <filesystem>

namespace fs = std::filesystem;

struct FileData
{
    fs::file_time_type timeLastWrite;
};