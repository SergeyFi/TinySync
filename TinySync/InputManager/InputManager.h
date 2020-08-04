﻿#pragma once
#include <memory>

#include "IInputManager.h"
#include "../CommandDecoder/ICommandDecoder.h"
#include "../CommandDecoder/CommandDecoder.h"

class InputManager : public IInputManager
{
public:

    InputManager();

    void InputArguments(int argc, char* argv[]) override;

private:

    std::shared_ptr<ICommandDecoder> Command_decoder;


};
