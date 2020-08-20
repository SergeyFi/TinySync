#pragma once

#include <memory>
#include "../OutputManager/IOutputManager.h"

class IGetOutputManager
{
public:

    virtual std::shared_ptr<IOutputManager> GetOutputManager() = 0;
};