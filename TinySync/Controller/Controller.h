#pragma once

#include <memory>
#include "ControllerInterface.h"
#include "../InputManager/IInputManager.h"

class Controller : public ControllerInterface
{
public:

    Controller(std::shared_ptr<IInputManager> Input_manager);

    void InputConsoleArgument(int argc, char* argv[]) override;

    void InputCommand(Command command) override;

private:

    std::shared_ptr<IInputManager> Input_manager;
};
