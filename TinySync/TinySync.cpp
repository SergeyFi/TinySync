#include <memory>

#include "Controller/Controller.h"
#include "Controller/IController.h"
#include "InputManager/InputManager.h"
#include "InputManager/IInputManager.h"
#include "OutputManager/OutputManager.h"


int main(int argc, char* argv[])
{
    std::shared_ptr<IInputManager> Input_manager{new InputManager()};

    std::shared_ptr<IOutputManager> Output_manager{new OutputManager()};

    std::shared_ptr<IController> Sync_controller{new Controller(true ,Input_manager, Output_manager)};

    Sync_controller->InputConsoleArgument(argc, argv);

    return 0;
}
