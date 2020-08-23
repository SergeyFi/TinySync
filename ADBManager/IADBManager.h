#pragma once

#include <string>
#include <vector>

class IADBManager
{

public:
    virtual void TransferFilesToDevice(std::string deviceID, std::string originPath, std::string targetPath) const = 0;

    virtual void TransferFilesFromDevice(std::string deviceID, std::string originPath, std::string targetPath) const = 0;

    virtual const std::vector<std::string> GetDevicesID() const;
};