#pragma once

#include <memory>
#include "IController.h"
#include "../InputManager/IInputManager.h"

class Controller : public IController
{
public:

    Controller(std::shared_ptr<IInputManager> Input_manager);

    void InputConsoleArgument(int argc, char* argv[]) override;

    void InputCommand(Command command) override;

private:

    std::shared_ptr<IInputManager> Input_manager;
};
