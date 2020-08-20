#pragma once

#include "ISync.h"
#include <memory>

class IGetSyncManager
{
public:
    virtual std::shared_ptr<ISync> GetSyncManager() = 0;
};