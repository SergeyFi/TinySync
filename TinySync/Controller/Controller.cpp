#include "Controller.h"

Controller::Controller(std::shared_ptr<IInputManager> Input_manager)
{
    this->Input_manager = Input_manager;
}

void Controller::InputConsoleArgument(int argc, char* argv[])
{
}

void Controller::InputCommand(Command command)
{
}
