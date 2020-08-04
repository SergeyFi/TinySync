#pragma once

#include "../Controller/IController.h"

class IInputManager
{
public:

    virtual void InputArguments(int argc, char* argv[]) = 0;

    virtual void AddController(std::shared_ptr<IController> Controller) = 0;
};
