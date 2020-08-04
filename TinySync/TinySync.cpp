#include <memory>

#include "Controller/Controller.h"
#include "InputManager/InputManager.h"

int main(int argc, char* argv[])
{
    std::shared_ptr<InputManager> Input_manager{new InputManager()};

    std::shared_ptr<Controller> Sync_controller{new Controller(Input_manager)};

    Sync_controller->InputConsoleArgument(argc, argv);

    return 0;
}
