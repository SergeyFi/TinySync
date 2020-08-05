#include "Controller.h"

Controller::Controller(bool debug, std::shared_ptr<IInputManager> Input_manager,
    std::shared_ptr<IOutputManager> Output_manager, std::shared_ptr<ISync> Sync_manager)
{
    this->debug = debug;
    this->Input_manager = Input_manager;
    this->Output_manager = Output_manager;
    this->Sync_manager = Sync_manager;
    
}

void Controller::InputConsoleArgument(int argc, char* argv[])
{
    Input_manager->InputArguments(argc, argv);
}

void Controller::InputCommand(Commands command)
{
    if (debug)
    {
        Output_manager->PrintCommand(command);
    }
}
