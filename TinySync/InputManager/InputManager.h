#pragma once
#include "IInputManager.h"

class InputManager : public IInputManager
{
public:

    void InputArguments(int argc, char* argv[]) override;
};
